namespace ExploitMods {
    void platforms() {
        static GameObject* platL = nullptr;
        static GameObject* platR = nullptr;

        auto createPlatform = [](const char* handName) -> GameObject* {
            auto handObj = GameObject::Find(handName);
            if (!handObj) return nullptr;
            auto handTransform = handObj->GetTransform();
            if (!handTransform) return nullptr;
            GameObject* platform = GameObject::CreatePrimitive(PrimitiveType::Cube);
            if (!platform) return nullptr;
            auto platTransform = platform->GetTransform();
            if (platTransform) {
                platTransform->SetPosition(handTransform->GetPosition());
                platTransform->SetRotation(handTransform->GetRotation());
                platTransform->SetLocalScale({0.5f, 0.05f, 0.5f});
            }
            return platform;
        };

        auto destroyPlatform = [](GameObject* platform) {
            if (platform && platform->Alive()) {
                GameObject::Destroy(platform);
            }
        };

        bool rightGrab = XRInput::GetBoolFeature(BoolFeature::GripButton, Controller::Right);

        if (XRInput::GetBoolFeature(BoolFeature::GripButton, Controller::Left)) {
            if (!platL) {
                platL = createPlatform("LeftHand Controller");
            }
        } else if (platL) {
            destroyPlatform(platL);
            platL = nullptr;
        }

        if (rightGrab) {
            if (!platR) {
                platR = createPlatform("RightHand Controller");
            }
        } else if (platR) {
            destroyPlatform(platR);
            platR = nullptr;
        }
    }
}
