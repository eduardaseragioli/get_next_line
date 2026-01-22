*This project has been created as part of the 42 curriculum by eseragio.*

# Get Next Line

## Description

<img align="right" src="https://media2.giphy.com/media/v1.Y2lkPTc5MGI3NjExa2t0YnJ3a2xveGkyd2RjZ214Y2dicXpyZ2xpOGM5eGN1OWxjOGFjayZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/ToMjGprfCF0jkA7VHfa/giphy.gif" 
       alt="Piscine Duck" 
       style="width:400px; height:auto; border-radius:40px;"> 

**get_next_line** is a project at 42 where you create a function that reads one line at a time from a file descriptor.
The goal of this project is to understand file I/O, buffer management, and how to maintain persistent state across function calls using static variables.

This project significantly strengthened my knowledge in:

- File handling with file descriptors
- Buffer and string manipulation
- Dynamic memory management with `malloc` and `free`
- Managing persistent state with static variables
- Edge-case handling (EOF, large files, multiple FDs)

✅ **Project completed with 125% success** as part of my 42 journey.  
💻 **Language:** C

---

## Project Overview (Mandatory & Bonus)

The project is structured into a mandatory part and a bonus part.

### 🔹 Mandatory Part

#### Function Prototype

```c
char *get_next_line(int fd);
```

**Objective:**  
Create a function that returns one line per call, reading from a file descriptor until no data remains.

**Requirements:**
- Read one line at a time from any file descriptor
- Work with any `BUFFER_SIZE` value (defined at compilation)
- Use static variables to maintain leftover data between calls
- Return `NULL` when EOF is reached
- Handle files of any size

| Category | Description | Internal Logic | Allowed Functions |
|----------|-------------|----------------|-------------------|
| **Incremental Reading** | Read in chunks of size `BUFFER_SIZE` until a full line is found | `read()` + custom join/split logic | `read`, `malloc`, `free` |
| **String Processing** | Join buffers, search for `\n`, extract substrings | Custom helpers: `ft_strjoin`, `ft_strchr`, `ft_substr` | Only your own functions |
| **Persistent State** | Store leftover data for the next function call | `static char *stash` | - |

---

### ⭐ Bonus Part – Multiple File Descriptors

The bonus extends the function to support **multiple file descriptors simultaneously**, without cross-interference.

**Bonus Objectives:**
- Maintain a separate stash for each file descriptor
- Handle alternating reads between different FDs
- Ensure memory integrity and no leaks

| Category | Description | Requirements | Allowed Functions |
|----------|-------------|--------------|-------------------|
| **Multiple FD Support** | Each FD must preserve its own leftover data | Separate `stash[fd]` or structure | `read`, `malloc`, `free` |
| **Extra Robustness** | Stable behavior with mixed or alternating FD reads | Avoid memory leaks and corruption | - |

---

