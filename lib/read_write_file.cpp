///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Lewis Baker
// Licenced under MIT license. See LICENSE.txt for details.
///////////////////////////////////////////////////////////////////////////////

#include <cppcoro\read_write_file.hpp>

#if CPPCORO_OS_WINNT
# define WIN32_LEAN_AND_MEAN
# include <Windows.h>

cppcoro::read_write_file cppcoro::read_write_file::open(
	io_context& ioContext,
	const std::experimental::filesystem::path& path,
	file_open_mode openMode,
	file_share_mode shareMode,
	file_buffering_mode bufferingMode)
{
	return read_write_file(file::open(
		GENERIC_READ | GENERIC_WRITE,
		ioContext,
		path,
		openMode,
		shareMode,
		bufferingMode));
}

cppcoro::read_write_file::read_write_file(
	detail::win32::safe_handle&& fileHandle) noexcept
	: file(std::move(fileHandle))
	, readable_file(detail::win32::safe_handle{})
	, writable_file(detail::win32::safe_handle{})
{
}

#endif