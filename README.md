# Guess the World Educational Game

## Overview
This project is an educational game inspired by GeoGuessr, developed entirely in C++ using the SFML graphics and multimedia library. 
The goal is to identify geographic locations based on panoramic images, with no use of external APIs.

## Key Features
- 360° panoramic image navigation
- Country selection via interactive world map
- Visual and audio feedback based on the user's answers
- Mouse and keyboard support for navigation
- Interactive zoom and map panning
- Replay feature with random image selection

## Technologies Used
- C++17
- SFML 3.0 (graphics, audio, events)
- PNG image format (lossless compression)
- WAV for sound effects, OGG for background music

## Multimedia Details
- Images are raster-based and scaled automatically to fit the window.
- Country data is encoded using unique RGB values for each pixel.
- No network protocols or external services are used — the game is fully offline.

## How to Use
1. Launch the application — a start screen is displayed. [Insert screenshot: start screen]
2. Click 'Start' — a panoramic image view appears. [Insert screenshot: panoramic image with Guess button]
3. Click 'Guess' — the map interface is shown for selection. [Insert screenshot: map view with country selection]
4. Click on a country and then 'Confirm' — the result is shown with feedback. [Insert screenshot: result screen - victory or loss]
5. Click 'Play Again' to repeat or close the app to exit.

## Conclusion
The project offers a lightweight, engaging alternative to commercial GeoGuessr-style applications. 
Its completely offline nature, visual learning features, and modular structure make it suitable for educational environments, personal exploration, or classroom use.
