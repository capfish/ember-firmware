/* 
 * File:   Error.h
 * Author: Richard Greene
 * 
 * Provides a way to associate error messages with error codes.

 *  * Created on July 30, 2014, 2:02 PM
 */

#ifndef ERROR_H
#define	ERROR_H

#include <iostream>
#include <stdio.h>
#include <syslog.h>

#define ERR_MSG Error::GetMessage

enum ErrorCode
{
    Success = 0,
    
    SerialNumAccess = 1,
    I2cFileOpen = 2, 
    I2cSlaveAddress = 3,
    I2cWrite = 4,
    I2cLongString = 5,
    I2cReadWrite = 6,
    I2cReadRead = 7,
    GpioExport = 8,
    GpioDirection = 9,
    GpioEdge = 10,
    GpioInterrupt = 11,
    GpioInput = 12,
    FileDescriptorInUse = 13,
    NoFileDescriptor = 14,
    EpollCreate = 15,
    EpollSetup = 16,
    NegativeNumFiles = 17,
    UnexpectedEvent = 18,
    GpioUnexport = 19,
    InvalidInterrupt = 20,
    UnknownEventType = 21,
    ExposureTimerCreate = 22,
    MotorTimerCreate = 23,
    MotorTimeoutTimer = 24,
    ExposureTimer = 25,
    StatusPipeCreation = 26,
    CommandPipeCreation = 27,
    WebCommandPipeCreation = 28,
    CommandResponsePipeCreation = 29,
    StatusToWebPipeOpen = 30,
    UnknownTextCommand = 31,
    StatusJsonSave = 32,
    SendStringToPipeError = 33, 
    MotorTimeoutError = 34,
    FrontPanelError = 35,
    MotorError = 36,
    UnexpectedMotionEnd = 37,
    UnknownMotorEvent = 38,
    UnknownMotorStatus = 39,
    UnknownFrontPanelStatus = 40,
    HardwareNeeded = 41,
    UnknownCommandInput = 42,
    RemainingExposure = 43,
    SdlInit = 44,
    SdlSetMode = 45,
    SdlHideCursor = 46,
    LoadImageError = 47,
    NoImageForLayer = 48,
    CantShowImage = 49,
    CantShowBlack = 50,
    CantGetSetting = 51,
    CantSetSetting = 52,
    CantLoadSettings = 53,
    CantRestoreSettings = 54,
    CantSaveSettings = 55,
    CantWriteSettingsString = 56,
    CantReadSettingsString = 57,
    NoDefaultSetting = 58,
    UnknownSetting = 59,
    NoPrintData = 60,
    SeparationRpmOutOfRange = 61,
    PrintDataStageError = 62,
    InvalidPrintData = 63,
    PrintDataSettings = 64,
    PrintDataMove = 65,
    PrintDataRemove = 66,
    IllegalStateForPrintData = 67,
    UnknownPrintEngineState = 68,
    FrontPanelNotReady = 69,
    LongFrontPanelString = 70,
    UnknownErrorCode = 71,
    
    // Guardrail for valid error codes
    MaxErrorCode
};

class Error {
public:
    static const char* GetMessage(ErrorCode errorCode)
    {
        static bool initialized = false;
        static const char* messages[MaxErrorCode];
        if(!initialized)
        {
            // initialize the array of state names
            messages[Success] = "Success";
            
            messages[SerialNumAccess] = "Can't access board serial number";
            messages[I2cFileOpen] = "Couldn't open file in I2C_Device constructor";
            messages[I2cSlaveAddress] = "Couldn't set slave address in I2C_Device constructor";
            messages[I2cWrite] = "Error in I2C_Device::Write";
            messages[I2cLongString] = "String too long for I2C_Device::Write";
            messages[I2cReadWrite] = "Write error in I2C_Device::Read";
            messages[I2cReadRead] = "Read error in I2C_Device::Read";
            messages[GpioExport] = "Unable to export GPIO pin for %d";
            messages[GpioDirection] = "Unable to open direction handle for %d";
            messages[GpioEdge] = "Unable to open edge handle for %d";
            messages[GpioInterrupt] = "Unable to create interrupt %d";
            messages[GpioInput] = "Unable to open input for %d";
            messages[FileDescriptorInUse] = "File descriptor for %d already defined";
            messages[NoFileDescriptor] = "No file descriptor defined for subscription to event type %d";
            messages[EpollCreate] = "Couldn't create the epoll set";
            messages[EpollSetup] = "Couldn't set up epoll for %d";
            messages[NegativeNumFiles] = "Negative number of file descriptors %d";
            messages[UnexpectedEvent] = "Unexpected event from event type %d";
            messages[GpioUnexport] = "Unable to open GPIO pin for unexport";         
            messages[InvalidInterrupt] = "Invalid interrupt event type %d";
            messages[UnknownEventType] = "Unknown event type %d";
            messages[ExposureTimerCreate] = "Unable to create exposure timer";
            messages[MotorTimerCreate] = "Unable to create motor timeout timer";
            messages[MotorTimeoutTimer] = "Unable to set motor timeout timer";
            messages[ExposureTimer] = "Unable to set exposure timer";
            messages[StatusPipeCreation] = "Error creating named pipe used for printer status";
            messages[CommandPipeCreation] = "Error creating named pipe used for command input";
            messages[WebCommandPipeCreation] = "Error creating named pipe used for web command input";
            messages[CommandResponsePipeCreation] = "Error creating named pipe for responding to commands";
            messages[StatusToWebPipeOpen] = "Error opening named pipe for pushing status to web";
            messages[UnknownTextCommand] = "Unknown command text: '%s'";
            messages[StatusJsonSave] = "Can't save latest printer status in JSON";
            messages[SendStringToPipeError] = "Network interface can't send data";         
            messages[MotorTimeoutError] = "Timeout waiting for motor response";
            messages[FrontPanelError] = "Front panel error";
            messages[MotorError] = "Motor error";
            messages[UnexpectedMotionEnd] = "End of motion when none expected";
            messages[UnknownMotorEvent] = "Unknown pending motor event: %d";
            messages[UnknownMotorStatus] = "Unknown motor board status: %d";
            messages[UnknownFrontPanelStatus] = "Unknown front panel status: %d";
            messages[HardwareNeeded] = "Release build must have hardware!";
            messages[UnknownCommandInput] = "Unknown command input: %d";
            messages[RemainingExposure] = "Error reading remaining exposure time";
            messages[SdlInit] = "Could not initialize screen, SDL error: %s";
            messages[SdlSetMode] = "Could not set video mode, SDL error: %s";
            messages[SdlHideCursor] = "Could not hide cursor, SDL error: %s"; 
            messages[LoadImageError] = "Error loading image: %s";
            messages[NoImageForLayer] = "No image for layer %d";
            messages[CantShowImage] = "Can't show image for layer %d";
            messages[CantShowBlack] = "Can't clear the screen to black";
            messages[CantGetSetting] = "Can't get setting: %s";
            messages[CantSetSetting] = "Can't set setting: %s";
            messages[CantLoadSettings] = "Can't load settings file: %s";
            messages[CantRestoreSettings] = "Can't restore settings file: %s";
            messages[CantSaveSettings] = "Can't save settings file: %s";
            messages[CantWriteSettingsString] = "Can't write settings to a text string";
            messages[CantReadSettingsString] = "Can't read settings from a text string";
            messages[NoDefaultSetting] = "There is no default value for setting: %s";
            messages[UnknownSetting] = "There is no known setting named: %s";
            messages[NoPrintData] = "There is no data available to be printed";
            messages[SeparationRpmOutOfRange] = "Separation RPM offset value (%d) out of range (0-9)";
            messages[PrintDataStageError] = "Error staging print data";
            messages[InvalidPrintData] = "Print data invalid";
            messages[PrintDataSettings] = "Error loading settings from print file";
            messages[PrintDataMove] = "Error moving print data from staging directory to print data directory";
            messages[PrintDataRemove] = "Error removing contents of print data directory";
            messages[IllegalStateForPrintData] = "Printer must be in Home or Idle state to process print data, was in state %s";
            messages[UnknownPrintEngineState] = "Unknown print engine state: %d";
            messages[FrontPanelNotReady] = "Timeout awaiting front panel ready";
            messages[LongFrontPanelString] = "String too long (%d) to be shown on front panel";
           
            messages[UnknownErrorCode] = "Unknown error code: %d";
            initialized = true;
        }

        if(errorCode < Success ||
           errorCode >= MaxErrorCode)
        {
            // don't use LOGGER here, to avoid recursion
            char buf[255];
            sprintf(buf, messages[UnknownErrorCode], errorCode);
            syslog(LOG_WARNING, buf);
            std::cerr << buf << std::endl;
            return "";                                                              
        }
        return messages[errorCode];    
    }    
};

#endif	/* ERROR_H */
