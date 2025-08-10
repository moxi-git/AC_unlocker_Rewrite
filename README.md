# AC_Unlocker_Rewrite

## About

This tool unlocks DLC cars by replacing the `collider.kn5` files in each car folder.
It’s simple but effective for joining servers or offline play with DLC cars.

---

## Building (Windows)
```powershell
g++ main.cpp -o ac_unlocker_rewritten.exe -static-libgcc -static-libstdc++
```

---

## Usage

1. Download the executable from [releases](https://github.com/moxi-git/AC_unlocker_Rewrite/releases).
2. Place it in here `C:\Program Files (x86)\Steam\steamapps\common\assettocorsa\content` and run it.
3. When prompted, enter your Assetto Corsa content folder path:
   `C:\Program Files (x86)\Steam\steamapps\common\assettocorsa\content`
   (or leave empty to use the default).
4. The tool will overwrite the `collider.kn5` files in all cars to unlock DLC content.
5. Done! Enjoy the unlocked cars.

> Note: Run this every time you install new DLC cars/mods.
