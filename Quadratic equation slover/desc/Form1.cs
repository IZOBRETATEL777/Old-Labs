using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace desc
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        
    private void button2_Click(object sender, EventArgs e)
        {
            double a, b, c, r = 0;
            ///a
            if (textBox1.Text == String.Empty || textBox1.Text == "+")
                a = 1;
            else if (textBox1.Text == "-")
                a = -1;
            else
                a = Convert.ToDouble(textBox1.Text);
            //b
           
            if (textBox2.Text == String.Empty || textBox2.Text == "+")
                b = 1;
            else if (textBox2.Text == "-")
                    b = -1;
            else
                b = Convert.ToDouble(textBox2.Text);
            //c
            
            if (textBox3.Text == String.Empty)
                c = 0;
            else
                c = Convert.ToDouble(textBox3.Text);
            //r
            if (textBox4.Text == String.Empty)
                MessageBox.Show("Eror 404: /n/t You didn't input all values");
            else
                r = Convert.ToDouble(textBox4.Text);
            
            if (r != 0)
            {
                c -= r;
                r=0;
            }
            //D
            double D = Math.Pow(b, 2) - 4 * a * c;
            if (D < 0)
                MessageBox.Show("Erro 404: \n\t Solution can't be found.", "No solutions!");
            else if (D == 0)
            {
                double x = (-b - Math.Sqrt(D)) / 2 * a;
                string x1 = "One solution: ";
                x1 += Convert.ToString(x);
                MessageBox.Show(x1, "Solution");
            }
            else
            {
                double x1 = (-b - Math.Sqrt(D)) / 2 * a;
                string x_1 = Convert.ToString(x1);
                double x2 = (-b + Math.Sqrt(D)) / 2 * a;
                string x_2 = Convert.ToString(x2);
                string x = "First solution: " + x_1 + '\n' + "Second solution: " + x_2;
                MessageBox.Show(x, "Solutions");
            }
           

        }
        

    private void button1_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            textBox1.Clear();
            textBox3.Clear();
            textBox2.Clear();
            textBox4.Clear();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Form frm = new AboutBox1();
            frm.ShowDialog();
        }
    }

   




}
