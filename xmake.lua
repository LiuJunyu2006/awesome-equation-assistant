add_rules("mode.debug", "mode.release")

add_requires("vcpkg::symengine")
add_requires("vcpkg::boost-multiprecision")
add_requires("vcpkg::boost-optional")
add_requires("vcpkg::boost-rational")

target("awesome-equation-assistant")
    if is_plat("windows") then
        add_cxxflags("/bigobj")
    end

    add_rules("qt.widgetapp")

    add_headerfiles("src/*.h")
    --remove_headerfiles("src/ui_*.h")
    add_files("src/*.cpp")
    add_files("src/*.ui")
    add_files("src/*.h")
    --remove_files("src/ui_*.h")

    add_headerfiles("src/widgets/*.h")
    --remove_headerfiles("src/widgets/ui_*.h")
    add_files("src/widgets/*.cpp")
    add_files("src/widgets/*.ui")
    add_files("src/widgets/*.h")
    --remove_files("src/widgets/ui_*.h")

    add_headerfiles("src/math/*.h")

    add_headerfiles("src/solutions/*.h")
    add_files("src/solutions/*.cpp")
    add_files("src/solutions/*.h")

    add_files("resources/app.qrc")
    
    add_frameworks("QtWebEngineCore")
    add_frameworks("QtWebEngineWidgets")

    add_includedirs("src")

    add_packages("vcpkg::boost-multiprecision")
    add_packages("vcpkg::symengine")
    add_packages("vcpkg::boost-rational")
    add_packages("vcpkg::boost-optional")


--
-- If you want to known more usage about xmake, please see https://xmake.io
--
-- ## FAQ
--
-- You can enter the project directory firstly before building project.
--
--   $ cd projectdir
--
-- 1. How to build project?
--
--   $ xmake
--
-- 2. How to configure project?
--
--   $ xmake f -p [macosx|linux|iphoneos ..] -a [x86_64|i386|arm64 ..] -m [debug|release]
--
-- 3. Where is the build output directory?
--
--   The default output directory is `./build` and you can configure the output directory.
--
--   $ xmake f -o outputdir
--   $ xmake
--
-- 4. How to run and debug target after building project?
--
--   $ xmake run [targetname]
--   $ xmake run -d [targetname]
--
-- 5. How to install target to the system directory or other output directory?
--
--   $ xmake install
--   $ xmake install -o installdir
--
-- 6. Add some frequently-used compilation flags in xmake.lua
--
-- @code
--    -- add debug and release modes
--    add_rules("mode.debug", "mode.release")
--
--    -- add macro defination
--    add_defines("NDEBUG", "_GNU_SOURCE=1")
--
--    -- set warning all as error
--    set_warnings("all", "error")
--
--    -- set language: c99, c++11
--    set_languages("c99", "c++11")
--
--    -- set optimization: none, faster, fastest, smallest
--    set_optimize("fastest")
--
--    -- add include search directories
--    add_includedirs("/usr/include", "/usr/local/include")
--
--    -- add link libraries and search directories
--    add_links("tbox")
--    add_linkdirs("/usr/local/lib", "/usr/lib")
--
--    -- add system link libraries
--    add_syslinks("z", "pthread")
--
--    -- add compilation and link flags
--    add_cxflags("-stdnolib", "-fno-strict-aliasing")
--    add_ldflags("-L/usr/local/lib", "-lpthread", {force = true})
--
-- @endcode
--

