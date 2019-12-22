#ifndef SOUNDSYSTEM_H
#define SOUNDSYSTEM_H

#include <QObject>
#include <QSoundEffect>
#include <vector>
#include <QSound>
#include <iostream>

class SoundSystem : public QObject
{
    Q_OBJECT
    bool soundOn = true;
    QSoundEffect * success;
    QSoundEffect * bounce1;
    QSoundEffect * bounce2;
    QSoundEffect * yay;
    QSoundEffect * ballin;
    QSoundEffect * explosion;
    QSoundEffect * loginScreenMusic;
    QSoundEffect * levelSelectMusic;
    QSoundEffect * lessonScreenMusic;
    QSoundEffect * levelOneMusic;
    QSoundEffect * levelTwoMusic;
    QSoundEffect * levelThreeMusic;
    QSoundEffect * levelFourMusic;
    QSoundEffect * levelFiveMusic;
    QSoundEffect * levelSixMusic;
    QSoundEffect * extraMusic;


    std::vector<QSoundEffect *> bounces;
public:
    explicit SoundSystem(QObject *parent = 0);
public slots:
    void playSuccess();
    void playBounce();
    void playYay();
    void playBallin();
    void playExplosion();
    void playLoginMusic();
    void playLevelSelect();
    void playLessonMusic();
    void playOneMusic();
    void playTwoMusic();
    void playThreeMusic();
    void playFourMusic();
    void playFiveMusic();
    void playSixMusic();
    void playExtra();
signals:

public slots:
};

#endif // SOUNDSYSTEM_H
