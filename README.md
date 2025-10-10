# 🎮 Cub3D

**Raycasting Engine** - Ecole42 projesi kapsamında geliştirilmiş, 3D grafik rendering ve oyun motoru teknolojilerini öğreten bir C projesi.

## 📖 Proje Hakkında

Cub3D, klasik **Wolfenstein 3D** tarzında bir raycasting engine'dir. Bu proje, 2D haritalardan 3D perspektif görüntü oluşturma, texture mapping, sprite rendering ve oyun döngüsü gibi temel oyun geliştirme kavramlarını öğretir.

### 🎯 Proje Amacı

- **Raycasting Algoritması**: 2D haritadan 3D görüntü oluşturma
- **Texture Mapping**: Duvarlara texture uygulama
- **Sprite Rendering**: 2D sprite'ları 3D sahneye entegre etme
- **Oyun Döngüsü**: Gerçek zamanlı kullanıcı etkileşimi
- **Map Parsing**: .cub dosya formatından harita okuma

## 🏗️ Proje Yapısı

```
cub3D/
├── lib/                    # Kütüphaneler
│   ├── cub3d.h            # Ana header dosyası
│   ├── libft/             # 42 libft kütüphanesi
│   └── gnl/               # Get Next Line kütüphanesi
├── src/                   # Kaynak kodlar
│   ├── checker/           # Harita ve dosya doğrulama
│   ├── cleanup/           # Bellek yönetimi
│   ├── executor/          # Oyun döngüsü ve rendering
│   ├── parser/            # Dosya parsing
│   └── utils/             # Yardımcı fonksiyonlar
├── maps/                  # Örnek harita dosyaları
├── textures/              # Texture dosyaları
└── main.c                 # Ana program
```

## 🚀 Kullanım

### Derleme
```bash
make
```

### Çalıştırma
```bash
./cub3D [map_file.cub]
```

### Örnek Kullanım
```bash
./cub3D maps/example.cub
```

## 🎮 Kontroller

| Tuş | Açıklama |
|-----|----------|
| `W` | İleri git |
| `S` | Geri git |
| `A` | Sola dön |
| `D` | Sağa dön |
| `←` | Sola bak |
| `→` | Sağa bak |
| `ESC` | Çıkış |

## 📁 Map Format (.cub)

```cub
# Harita ayarları
NO ./textures/north.xpm    # Kuzey duvar texture'ı
SO ./textures/south.xpm    # Güney duvar texture'ı
WE ./textures/west.xpm     # Batı duvar texture'ı
EA ./textures/east.xpm     # Doğu duvar texture'ı

F 220,100,0               # Zemin rengi (RGB)
C 225,30,0                 # Tavan rengi (RGB)

# Harita (1=duvar, 0=boş, N/S/E/W=oyuncu başlangıç pozisyonu)
1111111111111111111111111
1000000000000000000000001
1000000000000000000000001
1000000000000000000000001
1000000000000000000000001
1111111111111111111111111
```

## 🔧 Teknik Özellikler

### Raycasting Algoritması
- **DDA (Digital Differential Analyzer)**: Ray-marching algoritması
- **Wall Detection**: Duvarların kesişim noktalarını bulma
- **Distance Calculation**: Kamera mesafesi hesaplama
- **Texture Mapping**: UV koordinatları hesaplama

### Rendering Pipeline
1. **Ray Generation**: Her pixel için ray oluşturma
2. **Intersection Testing**: Ray-harita kesişimi
3. **Distance Calculation**: Mesafe hesaplama
4. **Texture Sampling**: Texture'dan pixel alma
5. **Screen Rendering**: Piksel çizme

### Memory Management
- **Dynamic Allocation**: Harita boyutuna göre bellek ayırma
- **Texture Loading**: XPM dosyalarından texture yükleme
- **Cleanup Functions**: Bellek sızıntısı önleme

## 🎨 Görsel Özellikler

- ✅ **3D Perspective**: Gerçekçi 3D görünüm
- ✅ **Texture Mapping**: Duvarlara texture uygulama
- ✅ **Color Coding**: Zemin ve tavan renklendirme
- ✅ **Smooth Movement**: Akıcı hareket animasyonu
- ✅ **Collision Detection**: Duvar çarpışma kontrolü

## 🔍 Test Senaryoları

```bash
# Temel test
./cub3D maps/basic.cub

# Büyük harita testi
./cub3D maps/large.cub

# Texture testi
./cub3D maps/texture_test.cub
```

## 📊 Performans

- **FPS**: 60+ FPS (optimize edilmiş)
- **Memory Usage**: Dinamik bellek yönetimi
- **CPU Usage**: Efficient raycasting algoritması
- **Rendering**: Real-time 3D rendering

## 🛠️ Geliştirme Ortamı

- **Dil**: C
- **Kütüphaneler**: mlx (MiniLibX), libft
- **Derleyici**: gcc
- **Platform**: macOS/Linux
- **Graphics**: X11/OpenGL

## 📚 Öğrenilen Kavramlar

- **Computer Graphics**: 3D rendering temelleri
- **Raycasting**: 3D görüntü oluşturma
- **Game Development**: Oyun döngüsü ve kontroller
- **File Parsing**: Dosya formatı işleme
- **Memory Management**: Dinamik bellek yönetimi
- **Mathematical Algorithms**: Trigonometri ve geometri

## 🎯 Proje Hedefleri

Bu proje ile aşağıdaki konularda deneyim kazanılmıştır:

1. **3D Graphics Programming**: Raycasting algoritması
2. **Game Engine Development**: Oyun motoru temelleri
3. **File Format Design**: .cub dosya formatı
4. **Real-time Rendering**: Gerçek zamanlı grafik
5. **User Input Handling**: Klavye kontrolleri
6. **Performance Optimization**: FPS optimizasyonu

## 🔧 Geliştirme Notları

- **Raycasting**: DDA algoritması kullanılarak efficient ray-marching
- **Texture Mapping**: UV koordinatları ile texture sampling
- **Collision Detection**: Grid-based collision system
- **Memory Management**: Proper cleanup ve leak prevention
- **Error Handling**: Kapsamlı hata kontrolü

## 📝 Lisans

Bu proje Ecole42 eğitim programı kapsamında geliştirilmiştir.

## 👨‍💻 Geliştirici

**Haluk Özdemir**  
42 Istanbul - Graphics Programming
**Betül Yıldız**
42 Istanbul - Graphics Programming

---

*Bu proje, 3D grafik programlama ve oyun geliştirme temellerini öğrenmek için tasarlanmıştır. Raycasting teknolojisini kullanarak 2D haritalardan 3D görüntü oluşturma sürecini modern C programlama teknikleri ile sunar.*

---

# 🎮 Cub3D

**Raycasting Engine** - A C project developed within the scope of Ecole42, teaching 3D graphics rendering and game engine technologies.

## 📖 About the Project

Cub3D is a raycasting engine in the style of classic **Wolfenstein 3D**. This project teaches fundamental game development concepts such as creating 3D perspective images from 2D maps, texture mapping, sprite rendering, and game loops.

### 🎯 Project Purpose

- **Raycasting Algorithm**: Creating 3D images from 2D maps
- **Texture Mapping**: Applying textures to walls
- **Sprite Rendering**: Integrating 2D sprites into 3D scenes
- **Game Loop**: Real-time user interaction
- **Map Parsing**: Reading maps from .cub file format

## 🏗️ Project Structure

```
cub3D/
├── lib/                    # Libraries
│   ├── cub3d.h            # Main header file
│   ├── libft/             # 42 libft library
│   └── gnl/               # Get Next Line library
├── src/                   # Source codes
│   ├── checker/           # Map and file validation
│   ├── cleanup/           # Memory management
│   ├── executor/          # Game loop and rendering
│   ├── parser/            # File parsing
│   └── utils/             # Helper functions
├── maps/                  # Example map files
├── textures/              # Texture files
└── main.c                 # Main program
```

## 🚀 Usage

### Compilation
```bash
make
```

### Execution
```bash
./cub3D [map_file.cub]
```

### Example Usage
```bash
./cub3D maps/example.cub
```

## 🎮 Controls

| Key | Description |
|-----|-------------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Turn left |
| `D` | Turn right |
| `←` | Look left |
| `→` | Look right |
| `ESC` | Exit |

## 📁 Map Format (.cub)

```cub
# Map settings
NO ./textures/north.xpm    # North wall texture
SO ./textures/south.xpm    # South wall texture
WE ./textures/west.xpm     # West wall texture
EA ./textures/east.xpm     # East wall texture

F 220,100,0               # Floor color (RGB)
C 225,30,0                 # Ceiling color (RGB)

# Map (1=wall, 0=empty, N/S/E/W=player starting position)
1111111111111111111111111
1000000000000000000000001
1000000000000000000000001
1000000000000000000000001
1000000000000000000000001
1111111111111111111111111
```

## 🔧 Technical Features

### Raycasting Algorithm
- **DDA (Digital Differential Analyzer)**: Ray-marching algorithm
- **Wall Detection**: Finding wall intersection points
- **Distance Calculation**: Camera distance calculation
- **Texture Mapping**: UV coordinate calculation

### Rendering Pipeline
1. **Ray Generation**: Creating rays for each pixel
2. **Intersection Testing**: Ray-map intersection
3. **Distance Calculation**: Distance calculation
4. **Texture Sampling**: Sampling pixels from texture
5. **Screen Rendering**: Pixel drawing

### Memory Management
- **Dynamic Allocation**: Memory allocation based on map size
- **Texture Loading**: Loading textures from XPM files
- **Cleanup Functions**: Memory leak prevention

## 🎨 Visual Features

- ✅ **3D Perspective**: Realistic 3D view
- ✅ **Texture Mapping**: Applying textures to walls
- ✅ **Color Coding**: Floor and ceiling coloring
- ✅ **Smooth Movement**: Smooth movement animation
- ✅ **Collision Detection**: Wall collision detection

## 🔍 Test Scenarios

```bash
# Basic test
./cub3D maps/basic.cub

# Large map test
./cub3D maps/large.cub

# Texture test
./cub3D maps/texture_test.cub
```

## 📊 Performance

- **FPS**: 60+ FPS (optimized)
- **Memory Usage**: Dynamic memory management
- **CPU Usage**: Efficient raycasting algorithm
- **Rendering**: Real-time 3D rendering

## 🛠️ Development Environment

- **Language**: C
- **Libraries**: mlx (MiniLibX), libft
- **Compiler**: gcc
- **Platform**: macOS/Linux
- **Graphics**: X11/OpenGL

## 📚 Learned Concepts

- **Computer Graphics**: 3D rendering fundamentals
- **Raycasting**: 3D image creation
- **Game Development**: Game loop and controls
- **File Parsing**: File format processing
- **Memory Management**: Dynamic memory management
- **Mathematical Algorithms**: Trigonometry and geometry

## 🎯 Project Goals

This project provides experience in the following areas:

1. **3D Graphics Programming**: Raycasting algorithm
2. **Game Engine Development**: Game engine fundamentals
3. **File Format Design**: .cub file format
4. **Real-time Rendering**: Real-time graphics
5. **User Input Handling**: Keyboard controls
6. **Performance Optimization**: FPS optimization

## 🔧 Development Notes

- **Raycasting**: Efficient ray-marching using DDA algorithm
- **Texture Mapping**: Texture sampling with UV coordinates
- **Collision Detection**: Grid-based collision system
- **Memory Management**: Proper cleanup and leak prevention
- **Error Handling**: Comprehensive error control

## 📝 License

This project was developed within the scope of the Ecole42 education program.

## 👨‍💻 Developer

**Haluk Özdemir**  
42 Istanbul - Graphics Programming
**Betül Yıldız**
42 Istanbul - Graphics Programming

---

*This project is designed to learn 3D graphics programming and game development fundamentals. It presents the process of creating 3D images from 2D maps using raycasting technology with modern C programming techniques.*