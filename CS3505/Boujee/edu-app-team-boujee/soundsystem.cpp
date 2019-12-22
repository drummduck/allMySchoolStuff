#include "soundsystem.h"

SoundSystem::SoundSystem(QObject *parent) : QObject(parent)
{
    //Make sounds like this with QSoundEffect
    bounce1 = new QSoundEffect(this);
    bounce1->setSource(QUrl::fromLocalFile("../edu-app-team-boujee/sounds/bounce1.wav"));

    bounce2 = new QSoundEffect(this);
    bounce2->setSource(QUrl::fromLocalFile("../edu-app-team-boujee/sounds/bounce2.wav"));

    success = new QSoundEffect(this);
    success->setSource(QUrl::fromLocalFile("../edu-app-team-boujee/sounds/Correct.wav"));

    yay = new QSoundEffect(this);
    yay->setSource(QUrl::fromLocalFile("../edu-app-team-boujee/sounds/yay.wav"));

    explosion = new QSoundEffect(this);
    explosion->setSource(QUrl::fromLocalFile("../edu-app-team-boujee/sounds/explosion.wav"));

    ballin = new QSoundEffect(this);
    ballin->setSource(QUrl::fromLocalFile("../edu-app-team-boujee/sounds/ballin.wav"));

    loginScreenMusic = new QSoundEffect(this);
    loginScreenMusic->setSource(QUrl::fromLocalFile("../edu-app-team-boujee/sounds/login.wav"));

    levelSelectMusic = new QSoundEffect(this);
    levelSelectMusic->setSource(QUrl::fromLocalFile("../edu-app-team-boujee/sounds/levelSelect.wav"));

    lessonScreenMusic = new QSoundEffect(this);
    lessonScreenMusic->setSource(QUrl::fromLocalFile("../edu-app-team-boujee/sounds/lesson.wav"));

    levelOneMusic = new QSoundEffect(this);
    levelOneMusic->setSource(QUrl::fromLocalFile("../edu-app-team-boujee/sounds/level1.wav"));

    levelTwoMusic = new QSoundEffect(this);
    levelTwoMusic->setSource(QUrl::fromLocalFile("../edu-app-team-boujee/sounds/level2.wav"));

    levelThreeMusic = new QSoundEffect(this);
    levelThreeMusic->setSource(QUrl::fromLocalFile("../edu-app-team-boujee/sounds/level3.wav"));

    levelFourMusic = new QSoundEffect(this);
    levelFourMusic->setSource(QUrl::fromLocalFile("../edu-app-team-boujee/sounds/level4.wav"));

    levelFiveMusic = new QSoundEffect(this);
    levelFiveMusic->setSource(QUrl::fromLocalFile("../edu-app-team-boujee/sounds/level5.wav"));

    levelSixMusic = new QSoundEffect(this);
    levelSixMusic->setSource(QUrl::fromLocalFile("../edu-app-team-boujee/sounds/Insanity.wav"));

    extraMusic = new QSoundEffect(this);
    extraMusic->setSource(QUrl::fromLocalFile("../edu-app-team-boujee/sounds/extraSong.wav"));

}

/**
 * @brief SoundSystem::playSuccess
 * Method used to play the Success sound effect for login.
 */
void SoundSystem::playSuccess(){
    if(soundOn){
        success->setVolume(.50);
        success->play();
    }
}

/**
 * @brief SoundSystem::playBounce
 * Method is used to play the ballBounce sound effect.
 */
void SoundSystem::playBounce(){
    if(soundOn){
        bounce1->setVolume(.50);
        bounce1->play();
    }
}

void SoundSystem::playYay(){
    if(soundOn){
        yay->setVolume(.35);
        yay->play();
    }
}

void SoundSystem::playExplosion(){
    if(soundOn){
        explosion->setVolume(.60);
        explosion->play();

    }
}

void SoundSystem::playBallin(){
    if(soundOn){
        ballin->play();
    }
}

void SoundSystem::playLoginMusic()
{
    if(soundOn){
        if(loginScreenMusic->isPlaying() == false)
        {
            loginScreenMusic->setVolume(.4);
            loginScreenMusic->setLoopCount(QSoundEffect::Infinite);
            loginScreenMusic->play();
        }

        else
        {
            loginScreenMusic->stop();
        }
    }
}

void SoundSystem::playLevelSelect()
{
    if(soundOn){
        if(levelSelectMusic->isPlaying() == false)
        {
            levelSelectMusic->setVolume(.4);
            levelSelectMusic->setLoopCount(QSoundEffect::Infinite);
            levelSelectMusic->play();
        }

        else
        {
            levelSelectMusic->stop();
        }
    }
}


void SoundSystem::playLessonMusic()
{
    if(soundOn){
        if(lessonScreenMusic->isPlaying() == false)
        {
            lessonScreenMusic->setVolume(.4);
            lessonScreenMusic->setLoopCount(QSoundEffect::Infinite);
            lessonScreenMusic->play();
        }

        else
        {
            lessonScreenMusic->stop();
        }
    }
}

void SoundSystem::playOneMusic()
{
    if(soundOn){
        if(levelOneMusic->isPlaying() == false)
        {
            levelOneMusic->setVolume(.4);
            levelOneMusic->setLoopCount(QSoundEffect::Infinite);
            levelOneMusic->play();
;
        }

        else
        {
            levelOneMusic->stop();
        }
    }
}

void SoundSystem::playTwoMusic()
{
    if(soundOn){
        if(levelTwoMusic->isPlaying() == false)
        {
            levelTwoMusic->setVolume(.4);
            levelTwoMusic->setLoopCount(QSoundEffect::Infinite);
            levelTwoMusic->play();
        }

        else
        {
            levelTwoMusic->stop();
        }
    }
}

void SoundSystem::playThreeMusic()
{
    if(soundOn){
        if(levelThreeMusic->isPlaying() == false)
        {
            levelThreeMusic->setVolume(.4);
            levelThreeMusic->setLoopCount(QSoundEffect::Infinite);
            levelThreeMusic->play();
        }

        else
        {
            levelThreeMusic->stop();
        }
    }
}

void SoundSystem::playFourMusic()
{
    if(soundOn){
        if(levelFourMusic->isPlaying() == false)
        {
            levelFourMusic->setVolume(.4);
            levelFourMusic->setLoopCount(QSoundEffect::Infinite);
            levelFourMusic->play();
        }

        else
        {
            levelFourMusic->stop();
        }
    }
}

void SoundSystem::playFiveMusic()
{
    if(soundOn){
        if(levelFiveMusic->isPlaying() == false)
        {
            levelFiveMusic->setVolume(.4);
            levelFiveMusic->setLoopCount(QSoundEffect::Infinite);
            levelFiveMusic->play();
        }

        else
        {
            levelFiveMusic->stop();
        }
    }
}

void SoundSystem::playSixMusic()
{
    if(soundOn){
        if(levelSixMusic->isPlaying() == false)
        {
            levelSixMusic->setVolume(.4);
            levelSixMusic->setLoopCount(QSoundEffect::Infinite);
            levelSixMusic->play();
        }

        else
        {
            levelSixMusic->stop();
        }
    }
}

void SoundSystem::playExtra()
{
    if(soundOn){
        if(levelSixMusic->isPlaying() == false)
        {
            extraMusic->setVolume(.4);
            extraMusic->setLoopCount(QSoundEffect::Infinite);
            extraMusic->play();
        }

        else
        {
            extraMusic->stop();
        }
    }
}



