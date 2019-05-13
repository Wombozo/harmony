class NaturalNote: public Note {

    private:
        std::string name;
        std::string fname;
        SharpNote sn;
        FlatNote fn;
        int semiToneCount;
    public:
        NaturalNote following;
        NaturalNote preceding;

    public:
        NaturalNote(std::string name, std::string fname);
        ~NaturalNote();

        std::string getName(void);
        std::string fetFName(void);
        SharpNote getSharpNote(void);
        FlatNote getFlatNote(void);
        int getSemiToneCount(void);

};
