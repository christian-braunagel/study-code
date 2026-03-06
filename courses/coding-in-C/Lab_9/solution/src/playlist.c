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
        printf("Error: Playlist reached maximum size (%d songs)\n", MAX_SONGS);
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

#include "../include/playlist.h"

/* -------------------------------------------------
 * Extension 1: Search Algorithms
 * ------------------------------------------------- */

Song *find_song_by_title(Playlist *playlist, const char *title)
{
    Song *current = playlist->p_head;

    while (current)
    {
        if (strcmp(current->title, title) == 0)
        {
            return current;
        }
        current = current->p_nextSong;
    }

    return NULL;
}

Song *find_song_recursive(Song *current, const char *title)
{
    if (current == NULL)
    {
        return NULL;
    }

    if (strcmp(current->title, title) == 0)
    {
        return current;
    }

    return find_song_recursive(current->p_nextSong, title);
}

/* -------------------------------------------------
 * Extension 2: Recursion – Counting Songs
 * ------------------------------------------------- */

int count_songs_recursive(const Song *current)
{
    if (current == NULL)
    {
        return 0;
    }

    return 1 + count_songs_recursive(current->p_nextSong);
}

/* -------------------------------------------------
 * Extension 3: Sorting Algorithms
 * ------------------------------------------------- */

// Bubble Sort
// static void swap_song_data(Song *a, Song *b)
// {
//     char *tmp_title = a->title;
//     char *tmp_artist = a->artist;

//     a->title = b->title;
//     a->artist = b->artist;

//     b->title = tmp_title;
//     b->artist = tmp_artist;
// }

// void sort_playlist_by_title(Playlist *playlist)
// {
//     if (!playlist->p_head)
//         return;

//     int swapped;
//     Song *ptr1;
//     Song *lptr = NULL;

//     do
//     {
//         swapped = 0;
//         ptr1 = playlist->p_head;

//         while (ptr1->p_nextSong != lptr)
//         {
//             if (strcmp(ptr1->title, ptr1->p_nextSong->title) > 0)
//             {
//                 swap_song_data(ptr1, ptr1->p_nextSong);
//                 swapped = 1;
//             }
//             ptr1 = ptr1->p_nextSong;
//         }
//         lptr = ptr1;

//     } while (swapped);
// }

// Insertion Sort
void sort_playlist_by_title(Playlist *playlist)
{
    Song *pCur = playlist->p_head;
    Song *sorted = NULL;

    // Playlist leer
    if (pCur == NULL)
    {
        return;
    }

    while (pCur != NULL)
    {
        // wird benötigt, um die while-Schleife weiter zu durchlaufen. Denn:
        // pCur->p_nextSong ist am Ende in der Regel auf die sortierte Liste umgebogen
        Song *pNext = pCur->p_nextSong;

        // sortierte Liste ist noch leer
        if (sorted == NULL)
        {
            sorted = pCur;
            pCur->p_nextSong = NULL; // aus alter Liste lösen
        }
        // Aktueller Titel (cur) muss vor ersten Titel in sortierter Liste (sorted)
        else if (strcmp(sorted->title, pCur->title) >= 0)
        {
            pCur->p_nextSong = sorted;
            sorted = pCur;
        }
        // Aktueller Titel muss an die richtige Stelle gesetzt werden
        else
        {
            Song *pTmp = sorted;
            while (pTmp->p_nextSong != NULL && strcmp(pTmp->p_nextSong->title, pCur->title) < 0)
            {
                pTmp = pTmp->p_nextSong;
            }
            pCur->p_nextSong = pTmp->p_nextSong;
            pTmp->p_nextSong = pCur;
        }

        pCur = pNext;
    }
    // neue sortierte Liste wird Playlist übergeben
    playlist->p_head = sorted;
}
