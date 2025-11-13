#include <windows.h>
#include <iostream>

using namespace std;

// Note frequencies (in Hz)
#define C4  262
#define CS4 277
#define D4  294
#define DS4 311
#define E4  330
#define F4  349
#define FS4 370
#define G4  392
#define GS4 415
#define A4  440
#define AS4 466
#define B4  494
#define C5  523
#define CS5 554
#define D5  587
#define DS5 622
#define E5  659
#define F5  698
#define FS5 740
#define G5  784
#define GS5 831
#define A5  880
#define AS5 932
#define B5  988
#define C6  1047
#define REST 0

// Note durations (in ms)
#define WHOLE 1600
#define HALF 800
#define QUARTER 400
#define EIGHTH 200
#define SIXTEENTH 100

void playNote(int frequency, int duration) {
    if (frequency == REST) {
        Sleep(duration);
    } else {
        Beep(frequency, duration);
    }
}

void melodicIntro() {
    cout << "🎵 Playing: Melodic Introduction\n";
    playNote(C5, EIGHTH);
    playNote(E5, EIGHTH);
    playNote(G5, EIGHTH);
    playNote(C6, QUARTER);
    playNote(G5, EIGHTH);
    playNote(E5, QUARTER);
    playNote(REST, EIGHTH);
    
    playNote(D5, EIGHTH);
    playNote(F5, EIGHTH);
    playNote(A5, EIGHTH);
    playNote(D5, QUARTER);
    playNote(F5, EIGHTH);
    playNote(A5, QUARTER);
}

void twinkleTwinkle() {
    cout << "🎵 Playing: Twinkle Twinkle Little Star\n";
    playNote(C5, QUARTER);
    playNote(C5, QUARTER);
    playNote(G5, QUARTER);
    playNote(G5, QUARTER);
    playNote(A5, QUARTER);
    playNote(A5, QUARTER);
    playNote(G5, HALF);
    
    playNote(F5, QUARTER);
    playNote(F5, QUARTER);
    playNote(E5, QUARTER);
    playNote(E5, QUARTER);
    playNote(D5, QUARTER);
    playNote(D5, QUARTER);
    playNote(C5, HALF);
}

void happyBirthday() {
    cout << "🎵 Playing: Happy Birthday\n";
    playNote(C5, EIGHTH + SIXTEENTH);
    playNote(C5, SIXTEENTH);
    playNote(D5, QUARTER);
    playNote(C5, QUARTER);
    playNote(F5, QUARTER);
    playNote(E5, HALF);
    
    playNote(C5, EIGHTH + SIXTEENTH);
    playNote(C5, SIXTEENTH);
    playNote(D5, QUARTER);
    playNote(C5, QUARTER);
    playNote(G5, QUARTER);
    playNote(F5, HALF);
}

void imperialMarch() {
    cout << "🎵 Playing: Imperial March (Star Wars)\n";
    playNote(A4, HALF);
    playNote(A4, HALF);
    playNote(A4, HALF);
    playNote(F4, QUARTER + EIGHTH);
    playNote(C5, EIGHTH);
    
    playNote(A4, HALF);
    playNote(F4, QUARTER + EIGHTH);
    playNote(C5, EIGHTH);
    playNote(A4, WHOLE);
    
    playNote(E5, HALF);
    playNote(E5, HALF);
    playNote(E5, HALF);
    playNote(F5, QUARTER + EIGHTH);
    playNote(C5, EIGHTH);
    
    playNote(GS4, HALF);
    playNote(F4, QUARTER + EIGHTH);
    playNote(C5, EIGHTH);
    playNote(A4, WHOLE);
}

void marioTheme() {
    cout << "🎵 Playing: Super Mario Bros Theme\n";
    playNote(E5, EIGHTH);
    playNote(E5, EIGHTH);
    playNote(REST, EIGHTH);
    playNote(E5, EIGHTH);
    playNote(REST, EIGHTH);
    playNote(C5, EIGHTH);
    playNote(E5, EIGHTH);
    playNote(REST, EIGHTH);
    playNote(G5, QUARTER);
    playNote(REST, QUARTER);
    playNote(G4, QUARTER);
    playNote(REST, QUARTER);
}

void jingleBells() {
    cout << "🎵 Playing: Jingle Bells\n";
    playNote(E5, QUARTER);
    playNote(E5, QUARTER);
    playNote(E5, HALF);
    playNote(E5, QUARTER);
    playNote(E5, QUARTER);
    playNote(E5, HALF);
    
    playNote(E5, QUARTER);
    playNote(G5, QUARTER);
    playNote(C5, QUARTER);
    playNote(D5, QUARTER);
    playNote(E5, WHOLE);
}

void ascendingArpeggio() {
    cout << "🎵 Playing: Ascending Arpeggio\n";
    playNote(C4, EIGHTH);
    playNote(E4, EIGHTH);
    playNote(G4, EIGHTH);
    playNote(C5, EIGHTH);
    playNote(E5, EIGHTH);
    playNote(G5, EIGHTH);
    playNote(C6, QUARTER);
    playNote(REST, EIGHTH);
    
    // Descending
    playNote(C6, EIGHTH);
    playNote(G5, EIGHTH);
    playNote(E5, EIGHTH);
    playNote(C5, EIGHTH);
    playNote(G4, EIGHTH);
    playNote(E4, EIGHTH);
    playNote(C4, QUARTER);
}

void displayMenu() {
    cout << "\n╔════════════════════════════════════════╗\n";
    cout << "║      🎼 BEEP ART MUSIC PLAYER 🎼      ║\n";
    cout << "╠════════════════════════════════════════╣\n";
    cout << "║ 1. Melodic Introduction               ║\n";
    cout << "║ 2. Twinkle Twinkle Little Star        ║\n";
    cout << "║ 3. Happy Birthday                     ║\n";
    cout << "║ 4. Imperial March (Star Wars)         ║\n";
    cout << "║ 5. Super Mario Bros Theme             ║\n";
    cout << "║ 6. Jingle Bells                       ║\n";
    cout << "║ 7. Ascending Arpeggio                 ║\n";
    cout << "║ 8. Play All                           ║\n";
    cout << "║ 0. Exit                               ║\n";
    cout << "╚════════════════════════════════════════╝\n";
    cout << "Choose a melody: ";
}

int main() {
    int choice;
    
    cout << "Welcome to the Beep Art Music Player!\n";
    cout << "Using Windows.h Beep function to create beautiful music.\n";
    
    do {
        displayMenu();
        cin >> choice;
        cout << "\n";
        
        switch(choice) {
            case 1:
                melodicIntro();
                break;
            case 2:
                twinkleTwinkle();
                break;
            case 3:
                happyBirthday();
                break;
            case 4:
                imperialMarch();
                break;
            case 5:
                marioTheme();
                break;
            case 6:
                jingleBells();
                break;
            case 7:
                ascendingArpeggio();
                break;
            case 8:
                cout << "🎭 Playing all melodies...\n\n";
                melodicIntro();
                Sleep(500);
                twinkleTwinkle();
                Sleep(500);
                happyBirthday();
                Sleep(500);
                imperialMarch();
                Sleep(500);
                marioTheme();
                Sleep(500);
                jingleBells();
                Sleep(500);
                ascendingArpeggio();
                break;
            case 0:
                cout << "👋 Thanks for listening! Goodbye!\n";
                break;
            default:
                cout << "❌ Invalid choice. Please try again.\n";
        }
        
        if (choice != 0) {
            cout << "\n✨ Melody complete!\n";
            Sleep(1000);
        }
        
    } while(choice != 0);
    
    return 0;
}