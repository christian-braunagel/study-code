/*
 * File: playlist.c
 * Description: Includes the code/logic for functions of playlist.h
 */
#include "../include/playlist.h"

/**
 * @brief Initialize a new playlist
 *
 * @param p_playlist pointer the playlist
 */
void init_playlist(Playlist *p_playlist)
{
    p_playlist->p_head = NULL;
    p_playlist->size = 0;
}

/**
 * @brief add a new song to the end of the playlist
 *
 * @param playlist pointer to playlist
 * @param title    title of the new song
 * @param artist   artist of the new song
 */
void add_song(Playlist *playlist, const char *title, const char *artist)
{
    if (playlist->size >= MAX_SONGS)
    {
        printf("Warning: Playlist reached maximum size (%d songs). New song discarded.\n", MAX_SONGS);
        return;
    }

    Song *newSong = malloc(sizeof(*newSong));
    if (!newSong)
        return;

    newSong->title = malloc(strlen(title) + 1);
    newSong->artist = malloc(strlen(artist) + 1);

    if (!newSong->title || !newSong->artist)
    {
        free(newSong->title);
        free(newSong->artist);
        free(newSong);
        return;
    }

    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    newSong->p_nextSong = NULL;

    if (!playlist->p_head)
    {
        playlist->p_head = newSong;
    }
    else
    {
        Song *last = playlist->p_head;
        while (last->p_nextSong)
            last = last->p_nextSong;
        last->p_nextSong = newSong;
    }

    playlist->size++;
}

/**
 * @brief print out all songs of the playlist
 *
 * @param playlist pointer to playlist
 */
void print_playlist(const Playlist *playlist)
{
    printf("Playlist contains %d song(s):\n", playlist->size);
    Song *current = playlist->p_head;
    while (current)
    {
        printf("Title: %s, Artist: %s\n", current->title, current->artist);
        current = current->p_nextSong;
    }
}

/**
 * @brief delete the first song of the playlist
 *
 * @param playlist pointer to playlist
 */
void delete_firstSong(Playlist *playlist)
{
    if (!playlist->p_head)
        return;

    Song *tmp = playlist->p_head;
    playlist->p_head = tmp->p_nextSong;

    free(tmp->title);
    free(tmp->artist);
    free(tmp);

    playlist->size--;
}

/**
 * @brief delete playlist and free up memory
 *
 * @param playlist pointer to playlist
 */
void delete_playlist(Playlist *playlist)
{
    while (playlist->p_head)
        delete_firstSong(playlist);
}
