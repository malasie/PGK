using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Zadanie3
{
    public partial class Form1 : Form
    {
        SimulationBox sb = new SimulationBox(new AlgX(), new AlgY()) { Width = 400, Height = 300 };
        public Form1()
        {
            InitializeComponent();

            bmp = new Bitmap(Width + 1000, Height + 400);

            Random r = new Random();
            for (int i = 0; i < 10; i++)
            {
                sb.addBall(new Ball()
                {
                    X = r.Next(20, sb.Width - 20),
                    Y = r.Next(20, sb.Height - 20),
                    Vx = r.Next(0, 4),
                    Vy = r.Next(0, 4),
                    R = 10
                });
            }
        }

        Bitmap bmp;

        private void timer1_Tick(object sender, EventArgs e)
        {
            sb.NextStep();
            Invalidate();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.FillRectangle(Brushes.AliceBlue, 0, 0, sb.Width, sb.Height);
            foreach (Ball b in sb.Balls)
            {
                e.Graphics.DrawEllipse(Pens.DarkBlue, b.X - b.R, b.Y - b.R, 2 * b.R, 2 * b.R);
            }
        }
    }
}
