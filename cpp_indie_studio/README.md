# BOMBERMANN

## Story

Kevin is a young boi coming from NY suburb, he got stuck in a prison filled with crates and brick walls. Only equiped with a stack of poor russian blyat grenades, he only wants one thing: BLOW THIS PLACE UP!

## WebSite

visit:

https://bomber-man.hubside.fr/

## Method Guide
### Player

### Map

```c++
void reciveinput(device, int player, int movement);
```
make a bomb from the field blow, index is the index of the bomb from the getBombs() method, power is the radius of the splode, /!\ bombs can be chained /!\
```c++
void showAscii();
```
print the map on terminal
```c++
std::vector<std::vector<int>> getMap();
```
get actual map ,'int' is the element enum
```c++
std::vector<std::pair<int, int>> getPlayers();
```
get players positions
```c++
std::vector<std::pair<int, int>> getBombs();
```
get active bombs list
