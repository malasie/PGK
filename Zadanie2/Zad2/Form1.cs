using System;
using System.Drawing;
using System.Windows.Forms;

namespace Zad2
{
    public partial class Form1 : Form
    {
        SimulationBox sb = new SimulationBox(new AlgX(), new AlgY()) { Width = 200, Height = 200 };
        public Form1()
        {
            InitializeComponent();

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

        Bitmap sprite = new Bitmap("sprite.png");


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

        private void button1_Click(object sender, EventArgs e)
        {
            timer1.Enabled = !timer1.Enabled;
        }


        int i = 0;
        int pos = 0;

        private void timer1_Tick(object sender, EventArgs e)
        {
            //sb.nextStep();
            //Invalidate();

            using (var g = CreateGraphics())
            {

                g.DrawImage(sprite,
                    new Rectangle(0, 0, 120, 130),
                    new Rectangle(i * 120, pos * 130, 120, 130), //src
                    GraphicsUnit.Pixel
                    );
            }

            i++;
            switch (pos)
            {
                case 0: if (i >= 3) i = 0; break;
                case 7: if (i >= 9) i = 0; break;
            }

        }
    }
}
