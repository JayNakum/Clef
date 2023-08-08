project "Clef"
  kind "StaticLib"
  language "C++"
  cppdialect "C++17"
  targetdir "bin/%{cfg.buildcfg}"
  staticruntime "off"

  files { "src/**.h", "src/**.cpp" }

  includedirs
  {
    "src",
    "../vendor/glfw/include",
    "%{IncludeDir.VulkanSDK}",
  }

  links
  {
    "GLFW",
    "%{Library.Vulkan}",
  }
  
  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

  filter "system:windows"
    systemversion "latest"
    defines { "CLEF_PLATFORM_WINDOWS" }

  filter "configurations:Debug"
    defines { "CLEF_DEBUG" }
    runtime "Debug"
    symbols "On"

  filter "configurations:Release"
    defines { "CLEF_RELEASE" }
    runtime "Release"
    optimize "On"
    symbols "Off"