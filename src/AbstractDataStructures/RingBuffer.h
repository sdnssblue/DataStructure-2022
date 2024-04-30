#pragma once

/// @brief ��������� ���������� �� ������������� ���������� ������.
struct RingBuffer
{
	/// @brief ��������� �����.
	int* Buffer;

	/// @brief ������ ������.
	int Size;

	/// @brief ������� ����� � ��������� ������.
	int UsedMemory;

	/// @brief ��������� ������ � ��������� ������.
	int FreeMemory;

	/// @brief ������, �� �������� ������������ ������.
	int IndexOutput;

	/// @brief ������, � ������� ������������ ������.
	int IndexInput;

	/// @brief ����� ����� ���������� ������.
	const int GrowthFactor = 2;
};

/// @brief ������� ��������� �����.
/// @param size - ������ ���������� ������.
/// @return ���������� ��������� �����.
RingBuffer* InitRingBuffer(int size);

/// @brief �������� ������ ���������� ������.
/// @param ringBuffer - ��������� �����.
void ResizeRingBuffer(RingBuffer* ringBuffer);

/// @brief ��������� ������� � ��������� �����.
/// @param ringBuffer - ��������� �����.
/// @param value - �������� ������������ �������� � ��������� �����.
void PushRingBuffer(RingBuffer* ringBuffer, int value);

/// @brief ����������� ������� �� ���������� ������.
/// @param ringBuffer - ��������� �����.
/// @return ���������� �������� ���������� ��������.
int PopRingBuffer(RingBuffer* ringBuffer);

/// @brief ���������� � ��������� �����.
/// @param ringBuffer - ��������� �����.
/// @return ���������� ���������� ���������� ����� � ��������� ������.
int FreeMemoryInfo(RingBuffer* ringBuffer);

/// @brief ���������� � ������� �����.
/// @param ringBuffer - ��������� �����.
/// @return ���������� ���������� �������� ����� � ��������� ������.
int UsedMemoryInfo(RingBuffer* ringBuffer);

/// @brief ������� ��������� �����.
/// @param ringBuffer - ��������� �����.
void DeleteRingBuffer(RingBuffer* ringBuffer);