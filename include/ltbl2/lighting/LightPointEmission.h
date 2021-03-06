#pragma once

#include <ltbl2/quadtree/QuadtreeOccupant.h>

namespace ltbl {
    class LightPointEmission : public QuadtreeOccupant {
    private:
    public:
        sf::Sprite _emissionSprite;
        sf::Vector2f _localCastCenter;

        float _sourceRadius;

        float _shadowOverExtendMultiplier;

        LightPointEmission()
            : _localCastCenter(0.0f, 0.0f), _sourceRadius(64.0f), _shadowOverExtendMultiplier(1.4f)
        {}

        sf::FloatRect getAABB() const {
            return _emissionSprite.getGlobalBounds();
        }

        void render(const sf::View &view, sf::RenderTexture &lightTempTexture, sf::RenderTexture &emissionTempTexture, const std::vector<QuadtreeOccupant*> &shapes, sf::Shader &unshadowShader, sf::Shader &lightOverShapeShader);
    };
}