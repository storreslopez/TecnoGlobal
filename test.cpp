#include <windows.h>

// ==================== BEEP ART MASTERPIECE ====================
// Title: "Windows Nocturne in C Major"
// A Study in Harmonic Ascent and Resolution
// =============================================================

// Note durations at ~100 BPM
#define Q 600   // Quarter note
#define E 300   // Eighth note
#define H 1200  // Half note
#define W 2400  // Whole note
#define S 150   // Sixteenth note
#define DE 450  // Dotted eighth

// Complete C Major Scale Frequencies
#define C3 131   // Deep C
#define G3 196   // Deep G
#define C4 262   // Middle C
#define E4 330   // E
#define G4 392   // G
#define C5 523   // Treble C (your original note!)
#define E5 659   // Treble E
#define G5 784   // Treble G
#define C6 1047  // High C
#define B5 988   // Leading tone
#define A5 880   // Submediant
#define D5  587

int main() {
    // 🎵 SECTION 1: Your Original Motif - Ascending Arpeggio
    // This transforms your 4 notes into a flowing cascade
    Beep(C4, E);       // Root
    Beep(E4, E);       // Third
    Beep(G4, E);       // Fifth
    Beep(C5, Q);       // Octave (your first note!)
    Beep(E5, E);       // Continue upward
    Beep(G5, E);       // Building tension
    Beep(C6, H);       // Climactic peak
    
    // 🎵 SECTION 2: Melodic Descent - The Answer
    // A complementary phrase that descends gracefully
    Beep(G5, Q);       // From the peak
    Beep(E5, E);       // Stepwise
    Beep(D5, E);       // Motion
    Beep(C5, H);       // Resolution
    
    // 🎵 SECTION 3: Bass Foundation - Harmonic Depth
    // Adds rhythmic and harmonic interest in the low register
    Beep(G3, Q);       // Dominant bass
    Beep(C4, Q);       // Tonic anchor
    Beep(E4, Q);       // Mediant color
    Beep(G4, DE);      // Builds anticipation
    
    // 🎵 SECTION 4: The Canon Layering Effect
    // Simulates two voices by alternating registers
    Beep(C5, S);       // High voice
    Beep(G3, S);       // Low voice
    Beep(E5, S);       // High
    Beep(C4, S);       // Low
    Beep(G5, S);       // High
    Beep(E4, S);       // Low
    Beep(C6, Q);       // Unified climax
    
    // 🎵 SECTION 5: Final Resolution & Arpeggiated Chord
    Beep(A5, Q);       // Slightly bittersweet
    Beep(G5, Q);       // Returns to dominant
    Beep(E5, DE);      // Prepares resolution
    Beep(C5, H);       // Final tonic
    
    // Grand Cadence - A C Major chord played as arpeggio
    Beep(C4, 80);
    Beep(E4, 80);
    Beep(G4, 80);
    Beep(C5, 80);
    Beep(E5, 80);
    Beep(G5, 80);
    Beep(C6, 400);     // Radiant final note
    
    return 0;
}