using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            bmp = new Bitmap(Width+1000, Height+400);
            InitializeComponent();
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            var g = this.CreateGraphics();

            g.DrawEllipse(Pens.Black, 100, 100, 50, 50);
            



        }

        int X = 0;
        int oldX = 0;
        bool P = true;
        Bitmap bmp;
        
        int Y=0;
        int k_X = 1;
        int k_Y = 1;
        int r = 50;

        private void timer1_Tick(object sender, EventArgs e)
        {

            /*
            Debug.WriteLine("Timer");

            if (P)
            {
                Invalidate();
            }

            {
                var g = this.CreateGraphics();

                g.DrawEllipse(Pens.Red, 100 + X, 150, 50, 50);

                X += 1;
            }
            P = !P;
            */

            /*
            var g = this.CreateGraphics();

            g.DrawEllipse(SystemPens.Control, 100 + oldX, 150, 50, 50);
            g.DrawEllipse(Pens.Blue, 100 + X, 150, 50, 50);
            oldX = X;
            X += 1;
            */

            /*
            var g = this.CreateGraphics();

            g.FillRectangle(SystemBrushes.Control, 0, 0, Width, Height);
            g.DrawEllipse(Pens.Blue, 100 + X, 150, 50, 50);
            oldX = X;
            X += 1;
            */


            var g = this.CreateGraphics();


            
            var gb = Graphics.FromImage(bmp);
            var gb2 = Graphics.FromImage(bmp);
            gb.FillRectangle(SystemBrushes.Control, 0, 0, Width, Height);
            Rectangle rect = new Rectangle(400, 100, 200, 150);
            gb.FillRectangle(new SolidBrush(Color.PowderBlue), rect);
            gb.FillEllipse(new SolidBrush(Color.RosyBrown), 50, 350, 250, 180);

            gb2.DrawEllipse(Pens.Blue, 200+X, 200+Y, r, r);
            oldX = X;
            X += k_X * 1;
            Y += k_Y * 1;

           
            g.DrawImage(bmp, 0, 0);
            

            var w = ClientRectangle.Width;
            var h = ClientRectangle.Height;

           

            if (X== -200 || X == w-200-r)
            {
                k_X *= -1;

            }
            if (Y == -200 || Y == h -200 - r)
            {
                k_Y *= -1;

            }

            Debug.WriteLine(X + " " + Y);


        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            /*
            var g = this.CreateGraphics();

            g.DrawEllipse(Pens.Blue, 250, 250, 150, 70);

            Debug.WriteLine("Odmalowano okno");
            */
        }


        private void Form1_Resize_1(object sender, EventArgs e)
        {
            bmp = new Bitmap(Width, Height);
        }
    }
}
