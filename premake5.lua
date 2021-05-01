workspace "Bamboo"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Bamboo"
    location "Bamboo"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include",
        "vendor/SFML/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "BM_PLATFORM_WINDOWS",
            "BM_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

        libdirs
        {
            "vendor/SFML/lib"
        }
    
        links
        {
            "opengl32.lib",
            "freetype.lib",
            "winmm.lib",
            "gdi32.lib",
            "openal32.lib",
            "flac.lib",
            "vorbisenc.lib",
            "vorbisfile.lib",
            "vorbis.lib",
            "ogg.lib",
            "ws2_32.lib"
        }
    
    filter "configurations:Debug"
        defines "BM_DEBUG"
        symbols "On"

        links
        {
            "sfml-audio-d.lib",
            "sfml-graphics-d.lib",
            "sfml-network-d.lib",
            "sfml-system-d.lib",
            "sfml-window-d.lib"
        }
    
    filter "configurations:Release"
        defines "BM_RELEASE"
        optimize "On"

        links
        {
            "sfml-audio.lib",
            "sfml-graphics.lib",
            "sfml-network.lib",
            "sfml-system.lib",
            "sfml-window.lib"
        }
    
    filter "configurations:Dist"
        defines "BM_DIST"
        optimize "On"

        links
        {
            "sfml-audio.lib",
            "sfml-graphics.lib",
            "sfml-network.lib",
            "sfml-system.lib",
            "sfml-window.lib"
        }

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Bamboo/vendor/spdlog/include",
        "vendor/SFML/include",
        "Bamboo/src"
    }

    links
    {
        "Bamboo"
    }

    postbuildcommands
    {
        ("{COPY} ../vendor/SFML/bin/ ../bin/" .. outputdir .. "/Sandbox")
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "BM_PLATFORM_WINDOWS",
        }

        libdirs
        {
            "vendor/SFML/lib"
        }
    
    filter "configurations:Debug"
        defines "BM_DEBUG"
        symbols "On"

        links
        {
            "sfml-audio-d.lib",
            "sfml-graphics-d.lib",
            "sfml-network-d.lib",
            "sfml-system-d.lib",
            "sfml-window-d.lib"
        }
    
    filter "configurations:Release"
        defines "BM_RELEASE"
        optimize "On"

        links
        {
            "sfml-audio.lib",
            "sfml-graphics.lib",
            "sfml-network.lib",
            "sfml-system.lib",
            "sfml-window.lib"
        }
    
    filter "configurations:Dist"
        defines "BM_DIST"
        optimize "On"

        links
        {
            "sfml-audio.lib",
            "sfml-graphics.lib",
            "sfml-network.lib",
            "sfml-system.lib",
            "sfml-window.lib"
        }