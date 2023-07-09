workspace "Hazel"
  configurations { "Debug", "Release", "Distribution" }
  architecture "x64"
  startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Hazel/vendor/GLFW/include"

include "Hazel/vendor/GLFW" -- Includes glfw premake file into this premake file

project "Hazel"
  location "Hazel"
  kind "SharedLib"
  language "C++"
  
  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

  pchheader "hzpch.h"
  pchsource "Hazel/src/hzpch.cpp"

  files
  {
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.cpp"
  }

  includedirs 
  {
    "%{prj.name}/src",
    "%{prj.name}/vendor/spdlog/include",
    "%{IncludeDir.GLFW}"
  }

  links
  {
    "GLFW",
    "opengl32.lib"
  }

  filter "system:windows"
    cppdialect "C++17"
    staticruntime "Off"
    systemversion "latest"

    defines
    {
      "HZ_PLATFORM_WINDOWS",
      "HZ_BUILD_DLL"
    }

    postbuildcommands
    {
      ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
    }
  
  filter "configurations:Debug"
    defines "HZ_DEBUG"
    symbols "On"
    runtime "Debug"
    buildoptions "/MDd"

  filter "configurations:Release"
    defines "HZ_RELEASE"
    optimize "On"
    runtime "Release"
    buildoptions "/MD"

  filter "configurations:Dist"
    defines "HZ_DIST"
    optimize "On"
    buildoptions "/MD"
  
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
    "Hazel/vendor/spdlog/include", 
    "Hazel/src"
  }

  links
  {
    "Hazel"
  }

  filter "system:windows"
    cppdialect "C++17"
    staticruntime "Off"
    systemversion "latest"

    defines
    {
      "HZ_PLATFORM_WINDOWS"
    }

  filter "configurations:Debug"
    defines "HZ_DEBUG"
    symbols "On"
    buildoptions "/MDd"


  filter "configurations:Release"
    defines "HZ_RELEASE"
    optimize "On"
    buildoptions "/MD"

  filter "configurations:Dist"
    defines "HZ_DIST"
    optimize "On"
    buildoptions "/MD"
  