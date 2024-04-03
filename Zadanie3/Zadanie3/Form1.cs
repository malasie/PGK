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

namespace Zadanie3
{
    public partial class Form1 : Form
    {
        SimulationBox sb = new SimulationBox(new AlgX(), new AlgY(),new AlgPh()) { Width = 400, Height = 300 };
        public Form1()
        {
            InitializeComponent();

            bmp = new Bitmap(Width, Height);

            Random r = new Random();
            for (int i = 0; i < 10; i++)
            {
                float X = r.Next(20, sb.Width - 20);
                float Y = r.Next(20, sb.Height - 20);
                float R = r.Next(1, 5) * 5;

                int j = 0;
                foreach (Ball b in sb.Balls)
                {
                    j++;
                    if (Math.Sqrt((X -b.X) * (X - b.X) + (Y - b.Y) * (Y - b.Y)) < R + b.R )
                    {
                        i--;
                        break;
                    }
                }
                if (j == sb.Balls.Count)
                {
                    sb.addBall(new Ball()
                    {
                        id= i,
                        X = X,
                        Y = Y,
                        Vx = r.Next(0, 4),
                        Vy = r.Next(0, 4),
                        R = R,
                        M = (float) r.Next(1,4)/3
                    });;;
 
                }
                foreach (Ball ball in sb.Balls)
                {
                    Debug.WriteLine($"{ball.M}");
                }
            }
        }

        Bitmap bmp;

        private void timer1_Tick(object sender, EventArgs e)
        {
            var g = this.CreateGraphics();

            var gb = Graphics.FromImage(bmp);
            gb.FillRectangle(Brushes.Blue, 0, 0, sb.Width+10, sb.Height+10);
            gb.FillRectangle(Brushes.DarkBlue, 10, 10, sb.Width-10, sb.Height-10);
            foreach (Ball b in sb.Balls)
            {
                gb.DrawEllipse(Pens.Yellow, b.X - b.R, b.Y - b.R, 2 * b.R, 2 * b.R);
            }

            sb.NextStep();
            sb.CollAlg();
            /*foreach (Collision coll in sb.collist)
            {
                Debug.WriteLine($"{coll.ball_1} {coll.ball_}");
            }
            Debug.WriteLine($" \n");*/

            g.DrawImage(bmp, 0, 0);


            //Invalidate();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            


        }
    }
}
