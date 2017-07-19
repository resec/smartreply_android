package com.easilydo.smartreply.signature;

public interface SignatureProcessorInterface {

    /**
     * Remove(Clean) the email content by providing sender names and recipients
     *
     * @param content The email content to be cleaned.
     * @param sender The sender name of the email.
     * @param recipients The recipient names of the email.
     * @return The cleaned content
     */
    String removeSignature(String content, String sender, String[] recipients);

}
