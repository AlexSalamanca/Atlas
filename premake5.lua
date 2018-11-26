workspace "Atlas"
	architecture "x64"
	
	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Atlas"
	location "Atlas"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.17134.0"

		defines{
			"AT_PLATFORM_WINDOWS",
			"AT_BUILD_DLL"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}


	filter "configurations:Debug"
		defines "AT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AT_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "AT_DIST"
		optimize "On"

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

	includedirs{
		"Atlas/vendor/spdlog/include",
		"Atlas/src"
	}

	links{
		"Atlas"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.17134.0"

		defines{
			"AT_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "AT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AT_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "AT_DIST"
		optimize "On"