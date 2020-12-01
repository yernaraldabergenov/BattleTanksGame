#pragma once 

#include "IGameObject.h"
#include "../../Renderer/Sprite.h"
#include "../../Renderer/SpriteAnimator.h"

#include <memory> 
#include <array>

namespace RenderEngine
{
	class Sprite;
}

class Water : public IGameObject
{
public:
	enum class EBlockLocation : uint8_t
	{
		TopLeft,
		TopRight,
		BottomLeft,
		BottomRight
	};

public:
	Water( const glm::vec2& position, const glm::vec2& size, float rotation );
	inline void Render() const override;
	inline void Update( const uint64_t delta ) override { spriteAnim.Update( delta ); };

private:
	void RenderBrick( const EBlockLocation eBlockLocation ) const;

private:
	std::shared_ptr<RenderEngine::Sprite> pSprite;
	RenderEngine::SpriteAnimator spriteAnim;
	std::array<glm::vec2, 4> blockOffsets; 
};