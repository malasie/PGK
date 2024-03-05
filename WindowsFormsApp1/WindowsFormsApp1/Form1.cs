using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Drawing.Drawing2D;
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
            k_X *= -1;
            k_Y *= -1;
            



        }
        int X = 0;
        int oldX = 0;
        bool P = true;
        Bitmap bmp;

        int Y=0;
        int k_X = 1;
        int k_Y = 1;
        int r = 50;
        int pr_X = 1;
        int pr_Y = 1;
        int max_pr = 5;

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
            var gb3 = Graphics.FromImage(bmp);
            gb.FillRectangle(SystemBrushes.Control, 0, 0, Width, Height);
            Rectangle rect = new Rectangle(0,0, 250, 400);
            gb3.TranslateTransform(800.0F, 300.0F);
            gb3.RotateTransform(45.0F);
            gb3.FillRectangle(new SolidBrush(Color.PaleGoldenrod), rect);
            gb.FillEllipse(new SolidBrush(Color.RosyBrown), 50, 350, 250, 180);
            gb.FillRectangle(new SolidBrush(Color.PowderBlue), 400, 100, 200, 150);

            gb2.DrawEllipse(Pens.Blue, 200+X, 200+Y, r, r);
            oldX = X;
            X += k_X * pr_X;
            Y += k_Y * pr_Y;

           
            g.DrawImage(bmp, 0, 0);
            

            var w = ClientRectangle.Width;
            var h = ClientRectangle.Height;

           

            if (X >= w-200-r)
            {
                X = w - 200 - r;
                k_X *= -1;

            }
            if (X <= -200)
            {
                X = -200;
                k_X *= -1;

            }
            if (Y >= h -200 - r)
            {
                Y = h - 200 - r;
                k_Y *= -1;

            }
            if (Y <= -200)
            {
                Y = -200;
                k_Y *= -1;

            }

            // Debug.WriteLine(X + " " + Y);


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

        private void Form1_Load(object sender, EventArgs e)
        {
            label1.Text = $"Predkość X: {pr_X}\nPredkość Y: {pr_Y}";

        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            Debug.WriteLine($"{e.KeyValue} {e.KeyCode}");
            
            
        }

        private void Form1_KeyPress(object sender, KeyPressEventArgs e)
        {
            Debug.WriteLine($"{e.KeyChar} {e.KeyChar}");
        }

        private void Form1_KeyUp(object sender, KeyEventArgs e)
        {
            Debug.WriteLine($"{e.KeyValue} {e.KeyCode}");
            if (e.KeyCode == Keys.Down & pr_Y>0)
            {
                pr_Y -= 1;
            }
            if (e.KeyCode == Keys.Up & pr_Y<max_pr)
            {
                pr_Y += 1;
            }

            if (e.KeyCode == Keys.Left & pr_X > 0)
            {
                pr_X -= 1;
            }
            if (e.KeyCode == Keys.Right & pr_X < max_pr)
            {
                pr_X += 1;
            }

            label1.Text = $"Predkość X: {pr_X}\nPredkość Y: {pr_Y}";
        }

        private void button2_Click(object sender, EventArgs e)
        {   
            pr_X = 1;
            pr_Y = 1;
            label1.Text = $"Predkość X: {pr_X}\nPredkość Y: {pr_Y}";
        }

     
    }
}
