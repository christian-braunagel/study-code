#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "../include/playlist.h"

/* === Tests === */

void test_init_playlist(void)
{
    Playlist p;
    init_playlist(&p);

    assert(p.p_head == NULL);
    assert(p.size == 0);
}

void test_add_song(void)
{
    Playlist p;
    init_playlist(&p);

    add_song(&p, "Song1", "Artist1");

    assert(p.size == 1);
    assert(p.p_head != NULL);
    assert(strcmp(p.p_head->title, "Song1") == 0);
    assert(strcmp(p.p_head->artist, "Artist1") == 0);
    assert(p.p_head->p_nextSong == NULL);
}

void test_delete_firstSong(void)
{
    Playlist p;
    init_playlist(&p);

    add_song(&p, "Song1", "Artist1");
    add_song(&p, "Song2", "Artist2");

    delete_firstSong(&p);

    assert(p.size == 1);
    assert(strcmp(p.p_head->title, "Song2") == 0);
}

void test_delete_firstSong_empty(void)
{
    Playlist p;
    init_playlist(&p);

    delete_firstSong(&p); // should not crash the program

    assert(p.size == 0);
    assert(p.p_head == NULL);
}

void test_delete_playlist(void)
{
    Playlist p;
    init_playlist(&p);

    add_song(&p, "Song1", "Artist1");
    add_song(&p, "Song2", "Artist2");

    delete_playlist(&p);

    assert(p.size == 0);
    assert(p.p_head == NULL);
}

void test_max_songs_limit(void)
{
    Playlist p;
    init_playlist(&p);

    for (int i = 0; i < MAX_SONGS; i++)
        add_song(&p, "X", "Y");

    assert(p.size == MAX_SONGS);

    add_song(&p, "Overflow", "Artist");
    assert(p.size == MAX_SONGS); // should not be increased
}

/* === Test-Runner === */

int main(void)
{
    test_init_playlist();
    test_add_song();
    test_delete_firstSong();
    test_delete_firstSong_empty(); // what happens if we delete first song from empty playlist
    test_delete_playlist();
    test_max_songs_limit(); // verify if the limit will be not be surpassed

    printf("Alle Playlist-Tests erfolgreich bestanden.\n");
    return 0;
}
