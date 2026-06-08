namespace ExploitMods {
    void teleportgun() {
        static GunUtility* tpGun = nullptr;

        if (!tpGun) {
            tpGun = new GunUtility([](RaycastHit hit) {
                if (hit.collider) {
                    
                    GameObject* localPlayer = Player::GetLocalPlayer();
                    if (localPlayer) {
                        
                        localPlayer->transform->position = hit.point;
                                    }
                }
            });
        }

        tpGun->DoGun();
    }
}
