void ExploitMods::noclip() {
    static bool lastVal = false;
    bool secon = XRInput::GetBoolFeature(BoolFeature::SecondaryButton, Controller::Right);
    
    if (lastVal != secon) {
        lastVal = secon;
        
        auto* type = MeshCollider::GetType();
        auto* objectsArray = GameObject::FindObjectsOfType(type);
        
        std::vector<BNM::UnityEngine::Object*> colliders;
        BNM::Structures::Mono::Array<BNM::UnityEngine::Object*>::ToVector(&colliders, objectsArray);
        
        for (auto* obj : colliders) {
            if (obj) {
                Collider::SetEnabled((Collider*)obj, !lastVal);
            }
        }
    }
}
