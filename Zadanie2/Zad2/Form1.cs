using System;
using System.ComponentModel.Design;
using System.Diagnostics;
using System.Drawing;
using System.Reflection.Emit;
using System.Windows.Forms;

namespace Zad2
{
    public partial class Form1 : Form
    {
        //SimulationBox sb = new SimulationBox(new AlgX(), new AlgY()) { Width = 200, Height = 200 };

        public Form1()
        {
            InitializeComponent();

            bmp = new Bitmap(Width + 1000, Height + 400);

            /*Random r = new Random();
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
            */
        }

        Bitmap bmp;
        Bitmap sprite = new Bitmap("sprite.png");
        Bitmap bird = new Bitmap("bird.png");
        Bitmap star = new Bitmap("star.png");
        Bitmap background = new Bitmap("background.jpg");


        int i = 0;
        int pos = 0;
        int X = 100;

        private void Form1_Load(object sender, EventArgs e)
        {
            using (var g = CreateGraphics())
            {

                g.DrawImage(background, new Rectangle(0, 0, ClientRectangle.Width, 478),
                 new Rectangle(-1672 + przes, 0, ClientRectangle.Width, 478), 
                 GraphicsUnit.Pixel);
            }

        }

       /* private void Form1_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.FillRectangle(Brushes.AliceBlue, 0, 0, sb.Width, sb.Height);
            foreach (Ball b in sb.Balls)
            {
                e.Graphics.DrawEllipse(Pens.DarkBlue, b.X - b.R, b.Y - b.R, 2 * b.R, 2 * b.R);
            }
        }
       */

        private void button1_Click(object sender, EventArgs e)
        {
            timer1.Enabled = !timer1.Enabled;
            if (button1.Text == "Start")
            {
                button1.Text = "Pause";
            }
            else
            {
                button1.Text = "Start";
            }
        }


        int kier = 0;
        int przes = 0;

        int j = 0;
        int k = 0;
        int x = 40;
        int pr_l = -40;
        int pr_r = 40;
        int pr = -40;

        int s_x = 100;
        int s_y = 50;
        int s_y1 = 10;
        int s_x1 = 200;
        int smax=70;
        int s = 3;
        int sk_y = 1;
        int sk_y1 = -1;
        int sk_x = 1;
        int sk_x1 = 1;




        private void timer1_Tick(object sender, EventArgs e)
        {
            //sb.nextStep();
            //Invalidate();

            var g = this.CreateGraphics();

            
            var gb = Graphics.FromImage(bmp);


            gb.DrawImage(background, new Rectangle(0, 0, ClientRectangle.Width, 478),
                new Rectangle(-1672 + przes, 0, ClientRectangle.Width, 478), //src
                GraphicsUnit.Pixel);

            gb.DrawImage(background, new Rectangle(0, 0, ClientRectangle.Width, 478),
                new Rectangle(przes, 0, ClientRectangle.Width, 478), //src
                GraphicsUnit.Pixel);



            gb.DrawImage(sprite,
                new Rectangle(X, 300, 120, 130),
                new Rectangle(i * 120, pos * 130, 120, 130), //src
                GraphicsUnit.Pixel);


            gb.DrawImage(star,
                new Rectangle(s_x, s_y, 30, 29),
                new Rectangle(s * 30, 0, 30, 29), //src
                GraphicsUnit.Pixel);

            gb.DrawImage(star,
                new Rectangle(s_x1, s_y1, 30, 29),
                new Rectangle(s * 30, 0, 30, 29), //src
                GraphicsUnit.Pixel);


            gb.DrawImage(bird,
                new Rectangle(x, 150, 87, 78),
                new Rectangle(j * 87, k * 78, 87, 78), //src
                GraphicsUnit.Pixel);

            s_x += 15 * sk_x;
            s_y += 5 * sk_y;

            s_x1 += 20 * sk_x1;
            s_y1 += 5 * sk_y1;


            i++;
            j++;
            x += pr;
            s++;

            if (s >= 6)
            {
                s = 0;
            }

            if (s_x <= 0 || s_x >= ClientRectangle.Width-30)
            {
                sk_x *= -1;
            }
            if (s_x1 <= 0 || s_x1 >= ClientRectangle.Width - 30)
            {
                sk_x1 *= -1;
            }

            if (s_y <= 0 || s_y >= smax)
            {
                sk_y *= -1;
            }
            if (s_y1 <= 0 || s_y1 >= smax)
            {
                sk_y1 *= -1;
            }


            if (kier == 1)
            {
                przes += 22;
                if (X >= 100)
                {
                    przes += 30;
                    X -= 30;
                }
            }

            else if (kier == -1)
            {
                przes -= 22;
                if (X <= 350)
                {
                    przes -= 30;
                    X += 30;
                }
            }


            if (przes >= 1672 + 800) { przes = 800; }
            else if (przes <= 0) { przes = 1672; }


            if (j>=5) { j = 0; }
            
            if (x >= ClientRectangle.Width-87) 
            { 
                k = 0;
                pr = pr_l;
            }
            else if ( x<=0 ) 
            { 
                k = 1;
                pr = pr_r;
            }
            Debug.WriteLine(s_x+" "+ s_y);


            switch (pos)
            {
                case 0: if (i >= 3) i = 0; break;
                case 2: if (i !=0) i = 0; break;
                case 5: if (i >= 9) i = 0; break;
                case 7: if (i >= 9) i = 0; break;
                
            }

            g.DrawImage(bmp, 0, 0);

        }

        


      

        private void Form1_KeyUp_1(object sender, KeyEventArgs e)
        {
            
            if (e.KeyCode == Keys.Left)
            {
                pos = 5;
                kier =-1;
                if (k == 0) 
                {  
                    pr_l = - 30 ; 
                }
                else
                {
                    pr_r = 50; 
                }

            }
            if (e.KeyCode == Keys.Right)
            {
                pos = 7;
                kier = 1;

                if (k == 1)
                {
                    pr_r = 30;
                }
                else
                {
                    pr_l = -50;
                }

            }

            if (e.KeyCode == Keys.Up)
            {
                i = 0;
                pos = 2;
                kier = 0;
            }
            if (e.KeyCode == Keys.Down)
            {
                i = 0;
                pos = 0;
                kier = 0;
            }
        }

        private void Form1_Resize(object sender, EventArgs e)
        {
            Bitmap bmp = new Bitmap(Width, Height);
        }
    }
}
