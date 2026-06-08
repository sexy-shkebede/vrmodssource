namespace ExploitMods {
    void longarms() {
        GameObject* v1 = GameObject::Find("GorillaPlayer");
        Transform* transform = v1->GetTransform();
        transform->SetLocalScale({armsLength, armsLength, armsLength});
    }
}
