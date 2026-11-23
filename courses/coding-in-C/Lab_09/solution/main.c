/*
 * File: main.c
 * Description: Program to demo usage of playlist
 */
#include "include/playlist.h"

/**
 * @brief exemplary usage of playlist
 *
 * @return int status code
 */
int main(void)
{
    Playlist myPlaylist;
    init_playlist(&myPlaylist);

    /* -------------------------------------------------
     * Create playlist
     * ------------------------------------------------- */
    add_song(&myPlaylist, "Crawling", "Linkin Park");
    add_song(&myPlaylist, "Layla", "Eric Clapton");
    add_song(&myPlaylist, "Esperanto", "Max Herre");
    add_song(&myPlaylist, "Nothing Else Matters", "Metallica");

    printf("Initial playlist:\n");
    print_playlist(&myPlaylist);

    /* -------------------------------------------------
     * Extension 1: Search algorithms
     * ------------------------------------------------- */
    printf("\nSearching for song 'Layla' (iterative):\n");
    Song *found = find_song_by_title(&myPlaylist, "Layla");
    if (found)
        printf("Found: %s by %s\n", found->title, found->artist);
    else
        printf("Song not found\n");

    printf("\nSearching for song 'Esperanto' (recursive):\n");
    found = find_song_recursive(myPlaylist.p_head, "Esperanto");
    if (found)
        printf("Found: %s by %s\n", found->title, found->artist);
    else
        printf("Song not found\n");

    /* -------------------------------------------------
     * Extension 2: Recursive counting
     * ------------------------------------------------- */
    int count = count_songs_recursive(myPlaylist.p_head);
    printf("\nNumber of songs (recursive): %d\n", count);

    /* -------------------------------------------------
     * Extension 3: Sorting
     * ------------------------------------------------- */
    printf("\nSorting playlist by title...\n");
    sort_playlist_by_title(&myPlaylist);

    printf("Playlist after sorting:\n");
    print_playlist(&myPlaylist);

    /* -------------------------------------------------
     * Cleanup
     * ------------------------------------------------- */
    delete_playlist(&myPlaylist);

    return 0;
}
