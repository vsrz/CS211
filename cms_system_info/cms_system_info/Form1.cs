using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace cms_system_info
{
  public partial class Form1 : Form
  {
    SystemSoftwareInformation s = new SystemSoftwareInformation();
    SystemHardwareInformation h = new SystemHardwareInformation();

    public Form1()
    {
      InitializeComponent();
      h.RefreshAll();
      RefreshSystemData();

    }
    
    private void button1_Click(object sender, EventArgs e)
    {
      h.RefreshAll();
      s.RefreshAll();
      Update();
      s.RefreshAll();
    }

    private void RefreshSystemData()
    {
      //textBox1.Text = h.GetCpuVendor + " " + h.GetCpuId + " " + h.GetCpuSpeed;
      //textBox2.Text = h.GetGraphicsDeviceDescription + " " + h.GetGraphicsMemory;
      textBox1.Text = "NICAdap: " + h.GetNetworkAdapterType;
      textBox2.Text = "NICStat" + h.GetNetworkConnectionStatus;
      textBox3.Text = "NICIFCnt: " + h.GetNetworkInterfaceCount;
      textBox4.Text = "HDType: " + h.GetHardDriveInterfaceType;
      textBox5.Text = h.GetHardDriveCapacity;
      textBox6.Text = h.GetHardDriveModel;
    }
  }
}
