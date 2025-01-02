int truckTour(vector<vector<int>> petrolpumps) {
    int start = 0;
    int totalPetrol = 0;
    int netDistance = 0;

    for (int i = 0; i < petrolpumps.size(); i++) {
        int petrol = petrolpumps[i][0];
        int distance = petrolpumps[i][1];

        totalPetrol += petrol - distance;
        netDistance += distance;

        if (totalPetrol < 0) {
            start = i + 1;
            totalPetrol = 0;
        }
    }

    return start;
}
