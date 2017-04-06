class Train
{
    private:
        int number;
        int num_of_stops;
        int num_of_coachs;
        int departure;
        int arrival;

    public:
        Train();
        void ReadData();
        void PrintData();
        void PrintRideTime();
        int GetNumber(){return number;}
};

