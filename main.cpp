#define __CL_ENABLE_EXCEPTIONS
// Enable use of deprecated APIs, purely because including cl.hpp
// generates an error when it encounters clCreateSampler,
// regardless as to whether it's called.
#define CL_USE_DEPRECATED_OPENCL_1_0_APIS
#define CL_USE_DEPRECATED_OPENCL_1_1_APIS
#define CL_USE_DEPRECATED_OPENCL_2_0_APIS
#include <CL/cl.hpp>

#include <iostream>

#define NOGDI
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

class Timer
{
public:
	Timer();

	double GetMilliseconds() const;

private:
	LARGE_INTEGER m_ticksPerSecond;
	LARGE_INTEGER m_start;
};

void CompileKernel(const cl::Context& context, const cl::Device& device);

int main(int argc, char* argv[])
{
	constexpr unsigned int CompilationRuns = 10;

	try
	{
		std::vector<cl::Platform> platforms;
		cl::Platform::get(&platforms);

		std::vector<cl::Device> devices;
		
		for (const cl::Platform& platform : platforms)
		{
			std::vector<cl::Device> platformDevices;
			platform.getDevices(CL_DEVICE_TYPE_ALL, &platformDevices);

			devices.insert(devices.end(), platformDevices.cbegin(), platformDevices.cend());
		}

		for (const cl::Device& device : devices)
		{
			std::string name;

			const std::string version = device.getInfo<CL_DEVICE_VERSION>();
			const std::string extensions = device.getInfo<CL_DEVICE_EXTENSIONS>();

			if (extensions.find("cl_amd_device_attribute_query") == std::string::npos)
				name = device.getInfo<CL_DEVICE_NAME>();
			else
				device.getInfo(CL_DEVICE_BOARD_NAME_AMD, &name);

			cl::Context context(device);

			std::cout << "Compiling kernel for device " << name << " (" << version << "):\n";

			double total = 0.0;

			for (unsigned int i = 0; i < CompilationRuns; ++i)
			{
				Timer timer;

				CompileKernel(context, device);

				const double ms = timer.GetMilliseconds();
				total += ms;
				std::cout << "Run " << i + 1 << ": " << ms << "ms\n";
			}

			std::cout << "Average: " << total / CompilationRuns << "ms\n\n";
		}
	}
	catch (const cl::Error& error)
	{
		std::cout << "Error: " << error.what() << "\n";
	}

	return 0;
}

void CompileKernel(const cl::Context& context, const cl::Device& device)
{
	std::string source = R"OPENCL(__kernel void Addition(__global float* input1, __global float* input2, __global float* output)
{
	int index = get_global_id(0);
	output[index] = input1[index] + input2[index];
}
)OPENCL";

	cl::Program program(context, source);
	
	try
	{
		program.build();
	}
	catch (const cl::Error& error)
	{
		std::cout << "Error: " << error.what() << "\n";

		const std::string log = program.getBuildInfo<CL_PROGRAM_BUILD_LOG>(device);
		std::cout << log << "\n";
	}
}

Timer::Timer()
{
	if (!::QueryPerformanceFrequency(&m_ticksPerSecond))
		m_ticksPerSecond.QuadPart = 0;

	::QueryPerformanceCounter(&m_start);
}

double Timer::GetMilliseconds() const
{
	if (!m_ticksPerSecond.QuadPart)
		return 0.0;

	LARGE_INTEGER t;
	::QueryPerformanceCounter(&t);

	return (t.QuadPart - m_start.QuadPart) * 1000.0 / static_cast<double>(m_ticksPerSecond.QuadPart);
}
