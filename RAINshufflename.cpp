void ExploitMods::ShuffleNames() {
    static float lastChangeTime = 0.0f;
    
    auto timeClass = BNM::Class("UnityEngine", "Time");
    auto timeProp = timeClass.GetProperty("time").Cast<float>();
    float currentTime = timeProp();
    
    if ((currentTime - lastChangeTime) >= 0.05f) {
        std::string randomName;
        ExploitMods::GenerateRandomName(&randomName, 8);
        
        PhotonVRManager::SetUsername(randomName);
        lastChangeTime = currentTime;
    }
}
