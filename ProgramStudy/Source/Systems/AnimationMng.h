#pragma once
#include <string>
#include <unordered_map>
#include <vector>

struct Animation
{
    int texId;
    int texColumns;

    int celWidth, celHeight;
    int celBaseId;
    int celCount;
    int loop;
};

// Singeton
class AnimationMng
{
public:
    using AnimationMap_t = std::unordered_map<std::string, Animation>;
public:
    static void Create();
    static void Destroy();
    static AnimationMng& Instance();

    static bool LoadAnimationFromXML(const std::string& file);
    static bool HasAnimationList(const std::string& listKey);
    static bool HasAnimation(const std::string& listKey, const std::string& state);
    static const Animation& GetAnimation(const std::string& listKey, const std::string& state);
    static int GetDuration_ms(int durationIndex);
private:
    AnimationMng();
    ~AnimationMng();
private:
    // Not allow copy and move
    // Body of these functions are empty
    AnimationMng(const AnimationMng&);
    AnimationMng(AnimationMng&&) noexcept;
    void operator = (const AnimationMng&);
    void operator = (AnimationMng&&) noexcept;

private:
    std::unordered_map<std::string, AnimationMap_t> m_listMap;
    std::vector<int> m_durations_ms;
    static AnimationMng* m_instance;
};

