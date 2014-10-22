#include "player.h"

using namespace Temere::Logic;

Player::Player() : Actor()
{
	mHead = nullptr;
	mBody = nullptr;
	mLegs = nullptr;
}

Player::Player(AnimationLogic& headLeft, AnimationLogic& headRight, AnimationLogic& bodyLeft, AnimationLogic& bodyRight, AnimationLogic& legsLeft, AnimationLogic& legsRight,
	unsigned int mTextureRows, unsigned int mTextureCols) : Actor()
{
	mHead = TEMERE_NEW SpriteAnimation(mTextureRows, mTextureCols);
	mBody = TEMERE_NEW SpriteAnimation(mTextureRows, mTextureCols);
	mLegs = TEMERE_NEW SpriteAnimation(mTextureRows, mTextureCols);

	mCurrentHeadIndex = headLeft.getStartIndex();
	mCurrentBodyIndex = bodyLeft.getStartIndex();
	mCurrentLegsIndex = legsLeft.getStartIndex();

	mHeadLeft = headLeft;
	mHeadRight = headRight;

	mBodyLeft = bodyLeft;
	mBodyRight = bodyRight;


	mLegsLeft = legsLeft;
	mLegsRight = legsRight;
}

Player::Player(AnimationLogic& headLeft, AnimationLogic& headRight, AnimationLogic& bodyLeft, AnimationLogic& bodyRight,
			   unsigned int mTextureRows, unsigned int mTextureCols) : Actor()
{
	mHead = TEMERE_NEW SpriteAnimation(mTextureRows, mTextureCols);
	mBody = TEMERE_NEW SpriteAnimation(mTextureRows, mTextureCols);
	mLegs = nullptr;

	mCurrentHeadIndex = headLeft.getStartIndex();
	mCurrentBodyIndex = bodyLeft.getStartIndex();

	mHeadLeft = headLeft;
	mHeadRight = headRight;

	mBodyLeft = bodyLeft;
	mBodyRight = bodyRight;
}

Player::Player(AnimationLogic& headLeft, AnimationLogic& headRight, AnimationLogic& headUp, AnimationLogic& headDown, AnimationLogic& bodyLeft, AnimationLogic& bodyRight,
	AnimationLogic& bodyUp, AnimationLogic& bodyDown, unsigned int mTextureRows, unsigned int mTextureCols) : Actor()
{
	mHead = TEMERE_NEW SpriteAnimation(mTextureRows, mTextureCols);
	mBody = TEMERE_NEW SpriteAnimation(mTextureRows, mTextureCols);
	mLegs = nullptr;

	mCurrentHeadIndex = headLeft.getStartIndex();
	mCurrentBodyIndex = bodyLeft.getStartIndex();

	mHeadLeft = headLeft;
	mHeadRight = headRight;
	mHeadUp = headUp;
	mHeadDown = headDown;

	mBodyLeft = bodyLeft;
	mBodyRight = bodyRight;
	mBodyUp = bodyUp;
	mBodyDown = bodyDown;
}

Player::Player(const Player& ref) : Actor(ref)
{
	TEMERE_UREF(ref)
}

Player::~Player()
{
	TEMERE_SAFE_DELETE(mHead)
	TEMERE_SAFE_DELETE(mBody)
	TEMERE_SAFE_DELETE(mLegs)
}

const Player& Player::operator=(const Player& ref)
{
	if(this != &ref)
	{
		Actor::operator=(ref);
	}
	return *this;
}

void Player::update(const float deltaTime)
{
	(void)deltaTime;
}
void Player::draw(const glm::mat4& projection, const  glm::mat4& view)
{
	mHead->Draw(projection, view, mCurrentHeadIndex);
	mBody->Draw(projection, view, mCurrentBodyIndex);

	if(mLegs != nullptr)
		mLegs->Draw(projection, view, mCurrentLegsIndex);
}
void Player::loadShaders(const std::string& vertexShader_path, const std::string& fragmentShader_path)
{
	mHead->loadShaders(vertexShader_path, fragmentShader_path);
	mBody->loadShaders(vertexShader_path, fragmentShader_path);

	if(mLegs != nullptr)
		mLegs->loadShaders(vertexShader_path, fragmentShader_path);
}

bool Player::loadTexture(const std::string& texturePath)
{
	bool result = true;
	result = mHead->loadTexture(texturePath);

	if(!result)
		return false;

	result = mBody->loadTexture(texturePath);

	if(mLegs != nullptr)
		result = mLegs->loadTexture(texturePath);

	return result;
}

void Player::moveLeft(const float deltaTime)
{
	mCurrentHeadIndex = mHeadLeft.getNextIndex();
	mCurrentBodyIndex = mBodyLeft.getNextIndex();
	mCurrentLegsIndex = mLegsLeft.getNextIndex();
	
	glm::vec3 newPos = mHead->getPosition();
	newPos.x += 0.05f;
	setPosition(newPos);
	std::cout << "Pos: " << newPos.x << std::endl;

	(void)deltaTime;
}

void Player::moveRight(const float deltaTime)
{
	mCurrentHeadIndex = mHeadRight.getNextIndex();
	mCurrentBodyIndex = mBodyRight.getNextIndex();
	mCurrentLegsIndex = mLegsRight.getNextIndex();

	glm::vec3 newPos = mHead->getPosition();
	newPos.x -= 0.05f;
	setPosition(newPos);
	std::cout << "Pos: " << newPos.x << std::endl;

	(void)deltaTime;
}

void Player::moveUp(const float deltaTime)
{
	mCurrentHeadIndex = mHeadUp.getNextIndex();
	mCurrentBodyIndex = mBodyUp.getNextIndex();
	
	glm::vec3 newPos = mHead->getPosition();
	newPos.y += 0.05f;
	setPosition(newPos);
	std::cout << "Pos: " << newPos.y << std::endl;

	(void)deltaTime;
}

void Player::moveDown(const float deltaTime)
{
	mCurrentHeadIndex = mHeadDown.getNextIndex();
	mCurrentBodyIndex = mBodyDown.getNextIndex();
	
	glm::vec3 newPos = mHead->getPosition();
	newPos.y -= 0.05f;
	setPosition(newPos);
	std::cout << "Pos: " << newPos.y << std::endl;

	(void)deltaTime;
}

void Player::setPosition(const glm::vec3& position)
{
	mHead->setPosition(position);
	mBody->setPosition(glm::vec3(position.x, position.y - 0.05, position.z));
	if(mLegs != nullptr)
		mLegs->setPosition(glm::vec3(position.x, position.y - mBody->getScale().y * 4.0f, position.z));
}

void Player::setScale(const glm::vec3& scale)
{
	mHead->setScale(scale);
	mBody->setScale(scale);
	if(mLegs != nullptr)
		mLegs->setScale(scale);
}

const glm::vec3& Player::getPosition()
{
	return mHead->getPosition();
}