namespace ExploitMods {
    void fly() {
        if (XRInput::GetFloatFeature(FloatFeature::Trigger, Controller::Right) > 0.5f) {
            GameObject* v6 = GameObject::Find("RightHand Controller");
            Transform* transform = v6->GetTransform();
            GameObject* v4 = GameObject::Find("GorillaPlayer");
            Rigidbody* component = (Rigidbody*)v4->GetComponent(Rigidbody::GetType());
            component->AddForce(transform->GetForward() * v0, (ForceMode)2);
        }
    }
}
