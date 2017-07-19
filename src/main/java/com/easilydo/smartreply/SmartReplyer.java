package com.easilydo.smartreply;

import java.util.Map;
import java.util.EnumMap;
import java.nio.IntBuffer;

import android.content.res.AssetManager;

import com.easilydo.smartreply.sentencepiece.SentencepieceProcessor;
import com.easilydo.smartreply.sentencepiece.SentencepieceProcessorInterface;

import org.tensorflow.contrib.android.TensorFlowInferenceInterface;

public class SmartReplyer {

    private static final String TAG = "SmartReplyer";

    private static final String INPUT_NODE_NAME_ENCODER_INPUTS = "encoder_inputs";
    private static final String INPUT_NODE_NAME_ENCODER_INTPUTS_LEN = "encoder_inputs_len";
    private static final String INPUT_NODE_NAME_DECODER_START_TOKENS = "deocder_start_tokens";
    private static final String OUTPUT_NODE_NAME = "dynamic_seq2seq/decoder/ArgMax_1";
    private static final String[] OUTPUT_NODE_NAMES = new String[]{OUTPUT_NODE_NAME};
    private static final int MAX_CONTENT_LEN = 1000;
    private static final int MAX_REPLY_LEN = 15;
    private static final int END_OF_SEQ_ID = 2;
    private static final String SP_FILE = "sentencepiece.model";
    private static final String MODEL_FILE = "inference.pb";
    private static final String TENSORFLOW_ASSET_PREFIX = "file:///android_asset/";

    private SentencepieceProcessorInterface sentencepieceProcessor;
    private TensorFlowInferenceInterface tensorflowInferenceInterface;
    private int[] encoderInputsArrayBug = new int[MAX_CONTENT_LEN];
    private int[] encoderInputsLenArrayBuf = new int[1];
    private int[] startTokensArrayBuf = new int[1];
    private long[] replyIdArrayBuf = new long[MAX_REPLY_LEN];

    public SmartReplyer(AssetManager assetManager) {
        final String tfModelPath = TENSORFLOW_ASSET_PREFIX + MODEL_FILE;
        sentencepieceProcessor = new SentencepieceProcessor(assetManager, SP_FILE);
        tensorflowInferenceInterface = new TensorFlowInferenceInterface(assetManager, tfModelPath);
    }

    public Map<Sentiment, String> reply(String content) {
        final int[] contentIds = sentencepieceProcessor.encode(content);
        final Map<Sentiment, String> replyMap = new EnumMap<Sentiment, String>(Sentiment.class);
        for (Sentiment sentiment : Sentiment.values()) {
            final int[] replyIds = reply(contentIds, sentiment);
            final String reply = sentencepieceProcessor.decode(replyIds);
            replyMap.put(sentiment, reply.replace("\u2581", " ").trim());
        }
        return replyMap;    
    }

    public String reply(String content, Sentiment sentiment) {
        final int[] contentIds = sentencepieceProcessor.encode(content);
        final int[] replyIds = reply(contentIds, sentiment);
        final String reply = sentencepieceProcessor.decode(replyIds);
        return reply.replace("\u2581", " ").trim();
    }

    private int[] reply(int[] ids, Sentiment sentiment) {
        int len = ids.length;
        if (len >= MAX_CONTENT_LEN) len = MAX_CONTENT_LEN;
        IntBuffer contentIds = IntBuffer.wrap(ids, 0, len);

        encoderInputsLenArrayBuf[0] = len;
        startTokensArrayBuf[0] = sentiment.getId();

        tensorflowInferenceInterface.feed(INPUT_NODE_NAME_ENCODER_INPUTS, contentIds, 1, len);
        tensorflowInferenceInterface.feed(INPUT_NODE_NAME_ENCODER_INTPUTS_LEN, encoderInputsLenArrayBuf, 1);
        tensorflowInferenceInterface.feed(INPUT_NODE_NAME_DECODER_START_TOKENS, startTokensArrayBuf, 1);
        tensorflowInferenceInterface.run(OUTPUT_NODE_NAMES);
        tensorflowInferenceInterface.fetch(OUTPUT_NODE_NAME, replyIdArrayBuf);

        int replyLen = 0;
        while (replyIdArrayBuf[replyLen] != END_OF_SEQ_ID && replyLen++ < MAX_REPLY_LEN);
        if (replyLen >= MAX_REPLY_LEN) replyLen = MAX_REPLY_LEN - 1;

        final int[] replyIds = new int[replyLen + 1];
        for (int i = 0; i <= replyLen; i++) {
            replyIds[i] = (int) replyIdArrayBuf[i];
        }
        
        return replyIds;    
    }
}
