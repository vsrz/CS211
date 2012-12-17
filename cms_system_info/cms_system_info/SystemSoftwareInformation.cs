using System;
using System.Collections.Generic;
using System.Text;
using System.Management;
using System.Net;
using System.Windows.Forms;

namespace cms_system_info
{
  class SystemSoftwareInformation
  {
    #region Constants
    const string NetworkTestBaseAddress = "http://shasta.cimmaronsoftware.com/testfiles/";
    const string NetworkTestFilename = "500k.txt";
    #endregion

    #region WMI Query/Searcher System Polls
    private static SelectQuery sqW32_ComputerSystem = new SelectQuery("Win32_ComputerSystem");
    private static ManagementObjectSearcher mosW32_ComputerSystem = new ManagementObjectSearcher(sqW32_ComputerSystem);
    #endregion
    
    #region SystemSoftwareInformation Values
    private string _BootupState, _ClientDomain, _SystemName;
    private string _TotalVirtualMemory, _AvailableVirtualMemory;
    private string _NetworkDownloadTime, _NetworkDownloadSpeed;
    #endregion

    #region Constructor/Destructor
    public SystemSoftwareInformation() { RefreshAll(); }
    ~SystemSoftwareInformation() { mosW32_ComputerSystem.Dispose(); }
    #endregion

    #region Private Members
    private void RefreshClientDomain()
    {
      try
      {
        foreach (ManagementObject service in mosW32_ComputerSystem.Get())
          _ClientDomain = service["Domain"].ToString();
      }
      catch (Exception ex)
      {
        _ClientDomain = ex.Message.ToString();
      }
    }

    private void RefreshBootupState()
    {
      try
      {
        foreach (ManagementObject service in mosW32_ComputerSystem.Get())
          _BootupState = service["BootupState"].ToString();
      }
      catch (Exception ex)
      {
        _BootupState = ex.Message.ToString();
      }
    }
    
    private void RefreshName()
    {
      try
      {
        foreach (ManagementObject service in mosW32_ComputerSystem.Get())
          _SystemName = service["Name"].ToString();
      }
      catch (Exception ex)
      {
        _SystemName = ex.Message.ToString();
      }
    }

    private void RefreshDownloadTest()
    {
      // Do Download
      try
      {
        WebClient client = new WebClient();
        client.BaseAddress = NetworkTestBaseAddress;
        double BeforeDownload = DateTime.Now.TimeOfDay.TotalSeconds;
        // Simulate Download
        System.Threading.Thread.Sleep(1000);
        //string data = client.DownloadString(NetworkTestFilename);
        double AfterDownload = DateTime.Now.TimeOfDay.TotalSeconds;
        /// TODO: Proper Math from Download Time -> Megabits/sec precision
        _NetworkDownloadTime = Convert.ToString(AfterDownload - BeforeDownload); ;
        _NetworkDownloadSpeed = Convert.ToString((500 / Convert.ToDouble(_NetworkDownloadTime)) * 0.0078125);
      }
      catch
      {
        _NetworkDownloadSpeed = "No connection established.";
        _NetworkDownloadTime = "No connection established.";
      }
    }

    #endregion

    #region Public Members
    /// <summary>
    /// Polls system for all information related to the system's software. 
    /// </summary>
    public void RefreshAll()
    {
      Application.DoEvents();
      RefreshClientDomain();
      RefreshBootupState();
      RefreshClientDomain();
      RefreshDownloadTest();
    }
    /// <summary>
    /// Returns string containing Network Domain of Client.
    /// </summary>
    public string GetClientDomain { get { return _ClientDomain; } }
    /// <summary>
    /// Returns string containing description of boot mode.
    /// </summary>
    public string GetBootupState { get { return _BootupState; } }
    /// <summary>
    /// Returns string containing description of computer system.
    /// </summary>
    public string GetSystemName { get { return System.Environment.MachineName; } }
    /// <summary>
    /// Returns string containing the detailed version number of the .NET Framework.
    /// </summary>
    public string GetFrameworkVersion { get { return System.Environment.Version.ToString(); } }
    /// <summary>
    /// Returns string containing available virtual memory.
    /// </summary>
    public string GetAvailableVirtualMemory { get { return _AvailableVirtualMemory; } }
    /// <summary>
    /// Returns string containing total virtual memory.
    /// </summary>
    public string GetTotalVirtualMemory { get { return _TotalVirtualMemory; } }
    /// <summary>
    /// Returns string containing speed of internet connection in Mbps.
    /// </summary>
    public string GetNetworkDownloadSpeed { get { return _NetworkDownloadSpeed; } }
    /// <summary>
    /// Returns string containing the length of time taken to download a 500K file.
    /// </summary>
    public string GetNetworkDownloadTime { get { return _NetworkDownloadTime; } }

    #endregion
  }
}

