using System;
using System.Collections.Generic;
using System.Text;
using System.Data;
using System.ComponentModel;
using System.Windows.Forms;
using Microsoft.Win32;
using System.Management;

namespace cms_system_info
{
  class SystemHardwareInformation
  {
    #region Constants
    const string Reg_CPU_Path = "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0";
    const string Reg_GFX_Path = "HARDWARE\\DEVICEMAP\\VIDEO";
    #endregion
    
    #region WMI Query/Searcher System Polls 
    // Computer System Queries
    private static SelectQuery sqW32_ComputerSystem = new SelectQuery("Win32_ComputerSystem");
    private static ManagementObjectSearcher mosW32_ComputerSystem = 
      new ManagementObjectSearcher(sqW32_ComputerSystem);
    // Video Controller Queries
    private static SelectQuery sqW32_VideoController = 
      new SelectQuery("Win32_VideoController");
    private static ManagementObjectSearcher mosW32_VideoController = 
      new ManagementObjectSearcher(sqW32_VideoController);
    // CPU Queries
    private static SelectQuery sqW32_Processor = new SelectQuery("Win32_Processor");
    private static ManagementObjectSearcher mosW32_Processor =
      new ManagementObjectSearcher(sqW32_Processor);
    // Physical Memory Queries
    private static SelectQuery sqW32_PhysicalMemory = new SelectQuery("Win32_PhysicalMemory");
    private static ManagementObjectSearcher mosW32_PhysicalMemory =
      new ManagementObjectSearcher(sqW32_PhysicalMemory);    
    // Network Adapter Queries
    private static SelectQuery sqW32_NetworkAdapter = new SelectQuery("Win32_NetworkAdapter");
    private static ManagementObjectSearcher mosW32_NetworkAdapter =
      new ManagementObjectSearcher(sqW32_NetworkAdapter);
    // Hard disk Queries
    private static SelectQuery sqW32_DiskDrive = new SelectQuery("Win32_DiskDrive");
    private static ManagementObjectSearcher mosW32_DiskDrive =
      new ManagementObjectSearcher(sqW32_DiskDrive);
    #endregion

    #region SystemHardwareInformation Values
    private static RegistryKey _HKLM;
    private string _CpuID, _CpuSpeed, _CpuVendor;
    private string _GfxAdapter, _GfxMemory, _DisplaySize;
    private string _SystemModel, _SystemManufacturer, _SystemType;
    private string _TotalPhysicalMemory, _AvailablePhysicalMemory;
    private string _NetworkAdapterType, _NetworkManufacturer, _NetworkConnectionStatus, _NetworkSpeed;
    private int _NetworkInterfaceCount = 0;
    private string _HardDriveCapacity, _HardDriveInterfaceType, _HardDriveModel;
    #endregion

    #region Constructor/Destructor
    public SystemHardwareInformation()
    {
      RefreshAll();
    }

    ~SystemHardwareInformation()
    {
      _HKLM.Close();
      mosW32_ComputerSystem.Dispose();
      mosW32_VideoController.Dispose();
      mosW32_Processor.Dispose();
      mosW32_PhysicalMemory.Dispose();
      mosW32_NetworkAdapter.Dispose();
      mosW32_DiskDrive.Dispose();
    }
    #endregion

    #region Private Members
    private void RefreshGraphicsInfo()
    {
      string Video0RegKey;

      try
      {
        // Open Path and get Video Card ID Tab
        _HKLM = Registry.LocalMachine.OpenSubKey(Reg_GFX_Path);
        Video0RegKey = _HKLM.GetValue("\\Device\\Video0").ToString();

        // Manipulate String
        Video0RegKey = Video0RegKey.Remove(0, 18);
        _HKLM = Registry.LocalMachine.OpenSubKey(Video0RegKey);

        // Retrieve Graphics Card ID String
        _GfxAdapter = _HKLM.GetValue("Device Description").ToString();
      }
      catch (Exception ex)
      {
        _GfxAdapter = ex.Message.ToString();
      }

      /// TODO: Convert from Bytes to Megs
      try
      {
        foreach (ManagementObject service in mosW32_VideoController.Get())
          _GfxMemory = service["AdapterRAM"].ToString();
      }
      catch (Exception ex)
      {
        _GfxMemory = ex.Message.ToString();
      }
      
      try
      {
        // Retrieve Screen Resolution
        _DisplaySize = SystemInformation.PrimaryMonitorSize.Height.ToString() + "x" + 
          SystemInformation.PrimaryMonitorSize.Width.ToString();
      }
      catch (Exception ex)
      {
        _DisplaySize = ex.Message.ToString();
      }
    }

    private void RefreshCPUInfo()
    {
      // Retrieve CPU_ID
      try
      {
        _HKLM = Registry.LocalMachine.OpenSubKey(Reg_CPU_Path);
        _CpuID = _HKLM.GetValue("Identifier").ToString();
      }
      catch (Exception ex)
      {
        _CpuID = ex.Message.ToString();
      }

      // Retrieve CPU Vendor Info
      try
      {
        _CpuVendor = _HKLM.GetValue("VendorIdentifier").ToString();
      }
      catch (Exception ex)
      {
        _CpuVendor = ex.Message.ToString();
      }


      // Retrieve CPU Clock Speed
      try
      {
        /// TODO: Format Field
        foreach (ManagementObject service in mosW32_Processor.Get())
          _CpuSpeed = service["CurrentClockSpeed"].ToString();
      }
      catch (Exception ex)
      {
        _CpuSpeed = ex.Message.ToString();
      }

    }

    private void RefreshManufacturer()
    {
      try
      {
        foreach (ManagementObject service in mosW32_ComputerSystem.Get())
          _SystemManufacturer = service["Manufacturer"].ToString();
      }
      catch (Exception ex)
      {
        _SystemManufacturer = ex.Message.ToString();
      }
    }

    private void RefreshModel()
    {
      try
      {
        foreach (ManagementObject service in mosW32_ComputerSystem.Get())
          _SystemModel = service["Model"].ToString();
      }
      catch (Exception ex)
      {
        _SystemModel = ex.Message.ToString();
      }
    }

    private void RefreshSystemType()
    {
      try
      {
        foreach (ManagementObject service in mosW32_ComputerSystem.Get())
          _SystemType = service["SystemType"].ToString();
      }
      catch (Exception ex)
      {
        _SystemType = ex.Message.ToString();
      }
    }

    private void RefreshPhysicalMemory()
    {
      try
      {
        /// TODO: Format total physical Memory!
        foreach (ManagementObject service in mosW32_PhysicalMemory.Get())
          _TotalPhysicalMemory = service["Capacity"].ToString();
      }
      catch (Exception ex)
      {
        _TotalPhysicalMemory = ex.Message.ToString();
      }

      /// TODO: Find Total Available PhysicalMemory
      _AvailablePhysicalMemory = "-1";
      
    }

    private void RefreshNetworkInfo()
    {
      try
      {
        int x = 0;
        foreach (ManagementObject service in mosW32_NetworkAdapter.Get())
        {
          _NetworkAdapterType = service["AdapterType"].ToString();
          _NetworkConnectionStatus = service["NetConnectionStatus"].ToString();
          _NetworkManufacturer = service["Manufacturer"].ToString();
          _NetworkSpeed = service["Speed"].ToString();
          _NetworkInterfaceCount = ++x;
        }
      }
      // TODO: Check->Throws a catch because no network adapters avail on this comp?
      catch
      {
        //MessageBox.Show(ex.Message.ToString());
        _NetworkInterfaceCount = 0;
      }
    }

    private void RefreshHardDiskInfo()
    {
      try
      {
        foreach (ManagementObject service in mosW32_DiskDrive.Get())
        {
          // TODO: Convert to gigs
          _HardDriveCapacity = Convert.ToString(((Convert.ToUInt64(service["TotalSectors"]) * 
            Convert.ToUInt64(service["BytesPerSector"])) / Convert.ToUInt64(1073741824))) + "GB";
          _HardDriveInterfaceType = Convert.ToString(service["InterfaceType"]);
          _HardDriveModel = Convert.ToString(service["Model"]);
        }
      }
      catch
      {
        _HardDriveCapacity = "0";
        _HardDriveInterfaceType = "";
        _HardDriveModel = "";
      }
    }

    #endregion

    #region Public Members
    
    /// <summary>
    /// Polls system for all information related to the system's hardware 
    /// </summary>
    public void RefreshAll()
    {
      Application.DoEvents();

      // Call all hardware refreshers
      RefreshCPUInfo();
      RefreshGraphicsInfo();
      RefreshManufacturer();
      RefreshModel();
      RefreshSystemType();
      RefreshPhysicalMemory();
      RefreshNetworkInfo();
      RefreshHardDiskInfo();
    }
    /// <summary>
    /// Returns string containing the description of the primary Graphics Device.
    /// </summary>
    public string GetGraphicsDeviceDescription { get { return _GfxAdapter; } }
    /// <summary>
    /// Returns string containing total physical memory on the Graphics Device.
    /// </summary>
    public string GetGraphicsMemory{get{return _GfxMemory;}}
    /// <summary>
    /// Returns string containing dimensions of the current display in Height x Width.
    /// </summary>
    public string GetDisplaySize { get { return _DisplaySize; } }
    /// <summary>
    /// Returns string containing the type of processor installed in the system.
    /// </summary>
    public string GetCpuId { get { return _CpuID; } }
    /// <summary>
    /// Returns string containing the name of the vendor of the CPU.
    /// </summary>
    public string GetCpuVendor { get { return _CpuVendor; } }
    /// <summary>
    /// Returns string containing the clock speed of the CPU in MHz.
    /// </summary>
    public string GetCpuSpeed { get { return _CpuSpeed; } }
    /// <summary>
    /// Returns string containing the type of the system (i.e. Intel x86).
    /// </summary>
    public string GetSystemType { get { return _SystemType; } }
    /// <summary>
    /// Returns string containing the manufacturer of the system (i.e. Dell).
    /// </summary>
    public string GetSystemManufacturer { get { return _SystemManufacturer; } }
    /// <summary>
    /// Returns string containing the model name or number of the system (i.e. Latitude X1).
    /// </summary>
    public string GetSystemModel { get { return _SystemModel; } }
    /// <summary>
    /// Returns string containing current available memory on the system.
    /// </summary>
    public string GetAvailablePhysicalMemory { get { return _AvailablePhysicalMemory; } }
    /// <summary>
    /// Returns string containing the capacity of the physical memory installed on the system.
    /// </summary>
    public string GetTotalPhysicalMemory { get { return _TotalPhysicalMemory; } }
    /// <summary>
    /// Returns array of string containing each Network Interface Type.
    /// </summary>
    public string GetNetworkAdapterType { get { return _NetworkAdapterType; } }
    /// <summary>
    /// Returns array of string containing the Manufacturer of the Network Card installed.
    /// </summary>
    public string GetNetworkManufacturer { get { return _NetworkManufacturer; } }
    /// <summary>
    /// Returns array of string containing the connection status of each network connection.
    /// </summary>
    public string GetNetworkConnectionStatus { get { return _NetworkConnectionStatus; } }
    /// <summary>
    /// Returns an integer with the number of interfaces found on the system.
    /// </summary>
    public int GetNetworkInterfaceCount { get { return _NetworkInterfaceCount; } }
    public string GetHardDriveCapacity { get { return _HardDriveCapacity; } }
    public string GetHardDriveModel { get { return _HardDriveModel; } }
    public string GetHardDriveInterfaceType { get { return _HardDriveInterfaceType; } }

    #endregion
  }
}
