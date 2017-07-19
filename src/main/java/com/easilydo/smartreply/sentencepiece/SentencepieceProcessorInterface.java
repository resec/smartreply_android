package com.easilydo.smartreply.sentencepiece;

public interface SentencepieceProcessorInterface {

    /**
     * Encode the content into id int array.
     *
     * @param content The content to be encoding into id array.
     * @return The encoded int array ids
     */
    int[] encode(String content);

    /**
     * Decode the ids back to String content.
     *
     * @param ids The id int array to be decoding back to String content.
     * @return The decoded String content
     */
    String decode(int[] ids);

}
