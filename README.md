# 🎵 Playlist Manager in C++

A feature-rich music playlist manager built using **C++** and **object-oriented programming principles**. It supports song management via a **doubly linked list**, with modular features like sorting, reordering, blocking artists, and more.

---

## 🚀 Features

- 🎧 Add and remove songs
- 📦 Move songs by index
- 🔁 Reverse the playlist
- 📊 Sort by title or duration
- 🧱 **NEW**: Blocklist artists to prevent their songs from being added
- 🎛️ Modular architecture using headers and clean separation of logic

---

## 🛠️ Technologies Used

- Language: **C++**
- Concepts: OOP, Dynamic Memory, STL (`unordered_set`, `function`)
- Structures: Custom **Doubly Linked List**
- Headers: Clean `Song.h` and `Playlist.h` separation

---


---

## 🔍 How Blocking Works

- Artists can be **blocked** using `blockArtist("Artist Name")`.
- Once blocked, **songs from that artist can't be added** to the playlist.
- You can **unblock** using `unblockArtist("Artist Name")`.

> 🧪 Try it in `main.cpp` and see the output!

---

## 📦 Example Usage

```cpp
playlist.blockArtist("Dua Lipa");
playlist.addSong(Song("1", "New Rules", "Dua Lipa", 230));  // ❌ Blocked
playlist.addSong(Song("2", "Perfect", "Ed Sheeran", 250));  // ✅ Added
