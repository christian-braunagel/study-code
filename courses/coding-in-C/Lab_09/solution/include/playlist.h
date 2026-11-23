/*
 * File: playlist.h
 * Description: Variables, data types and function declaration for playlist
 */
#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* -------------------- Configuration -------------------- */
#define MAX_SONGS 100 /* Maximum number of songs in a playlist */

/* -------------------- Data Structures -------------------- */
typedef struct Song
{
    char *title;
    char *artist;
    struct Song *p_nextSong;
} Song;

typedef struct Playlist
{
    Song *p_head;
    int size; /* current number of songs */
} Playlist;

/* -------------------- Function Declarations -------------------- */
void init_playlist(Playlist *p_playlist);
void add_song(Playlist *playlist, const char *title, const char *artist);
void print_playlist(const Playlist *playlist);
void delete_firstSong(Playlist *playlist);
void delete_playlist(Playlist *playlist);

/* --- Algorithm Extensions --- */
Song *find_song_by_title(Playlist *playlist, const char *title);
Song *find_song_recursive(Song *current, const char *title);
int count_songs_recursive(const Song *current);
void sort_playlist_by_title(Playlist *playlist);

#endif /* PLAYLIST_H */
