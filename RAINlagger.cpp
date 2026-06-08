void ExploitMods::lagger() {
    GameObject* player = GameObject::Find("GorillaPlayer");
    if (player) {
        Transform* transform = player->GetTransform();
        if (transform) {
            Vector3 centerPos = transform->GetPosition();
            
            for (int i = 0; i <= 1999; ++i) {
                float v3 = vcvts_n_f32_s32(rand(), 0x1Fu);
                float x = ((v3 - 0.5f) + (v3 - 0.5f)) * 50.0f;
                
                float v4 = vcvts_n_f32_s32(rand(), 0x1Fu);
                float y = ((v4 - 0.5f) + (v4 - 0.5f)) * 50.0f;
                
                float v5 = vcvts_n_f32_s32(rand(), 0x1Fu);
                float z = ((v5 - 0.5f) + (v5 - 0.5f)) * 50.0f;
                
                Vector3 spawnPos = centerPos + Vector3(x, y, z);
                std::string itemID = Settings::itemIDs[Settings::itemIndex];
                
                GameObject* spawnedItem = PhotonNetwork::Instantiate(itemID, spawnPos, Quaternion::identity, 0, nullptr);
                if (spawnedItem) {
                    GameObject::Destroy(spawnedItem);
                }
            }
        }
    } else {
        __android_log_print(6, "ByNameModding", "Lagger: Could not find player");
    }
}
