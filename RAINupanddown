namespace ExploitMods {
    void upanddown() {
        GameObject* v3 = GameObject::Find("GorillaPlayer");
        if (v3) {
            Rigidbody* Component = (Rigidbody*)v3->GetComponent(Rigidbody::GetType());
            if (Component) {
                float FloatFeature = XRInput::GetFloatFeature(FloatFeature::Trigger, Controller::Right);
                float v4 = XRInput::GetFloatFeature(FloatFeature::Trigger, Controller::Left);

                if (FloatFeature > 0.5f) {
                    Component->AddForce({0.0f, 1.0f, 0.0f}, (ForceMode)2);
                }

                if (v4 > 0.5f) {
                    Component->AddForce({0.0f, -1.0f, 0.0f}, (ForceMode)2);
                }
            }
        }
    }
}
