package com.easilydo.smartreply;

public enum Sentiment {
    POS(4), NEU(5), NEG(6);

    private int id;

    Sentiment(int id){
        this.id = id;
    }

    public int getId() {
        return id;
    }
}
