using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Timers;
using System.Drawing.Imaging;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace _223N_Project_5
{
    public partial class GoHome : Form
    {
        int RefreshRate = 60, angle = 0, speed = 4;
        double dxOffset = 0.0, dyOffset = 350.0;
        int failedCount = 0, successCount = 0;
        Rectangle dstRect;
        Rectangle earthRect;
        Bitmap bmp = new Bitmap("C:\\Users\\Sergio\\Pictures\\gala.png");
        ImageAttributes attr = new ImageAttributes();
        asteroid[] asteroids = new asteroid[3];
        string[] commands = { "close", "move", "set", "reset", "help" };
        string[] properties = { "success", "failure" };
        private static System.Timers.Timer graphic_area_refresh_clock = new System.Timers.Timer();
        private static System.Timers.Timer movement_tick = new System.Timers.Timer();
        private static System.Timers.Timer asteroid_movement_tick = new System.Timers.Timer();
        bool ship_clock_active = true, moveRight = false, moveLeft = false, openConsole = true, canDraw = false;
        Random random;

        //Form Initialization
        public GoHome()
        {
            DoubleBuffered = true;

            graphic_area_refresh_clock.Enabled = false;
            graphic_area_refresh_clock.Interval = (int)(1000.0 / RefreshRate);
            graphic_area_refresh_clock.Elapsed += new ElapsedEventHandler(updateDisplay);

            movement_tick.Enabled = false;
            movement_tick.Interval = (int)(1000.0 / RefreshRate);
            movement_tick.Elapsed += new ElapsedEventHandler(movement_ticking);
            
            asteroid_movement_tick.Enabled = false;
            asteroid_movement_tick.Interval = (int)(1000.0 / RefreshRate);
            asteroid_movement_tick.Elapsed += new ElapsedEventHandler(asteroid_movement);

            InitializeComponent();
        }

        //asteroid object
        public struct asteroid
        {
            public double x, y;
            private double initialX, initialY;
            public int speed;
            public int dir;
            public asteroid(double _x, double _y, int _dir)
            {
                x = _x;
                y = _y;
                dir = _dir;
                speed = 8;
                initialX = _x;
                initialY = _y;
            }
            public void reset()
            {
                x = initialX;
                y = initialY;
            }
        };

        //Movement handling functions
        protected void movement_ticking(System.Object sender, ElapsedEventArgs evt)
        {

            if (moveRight)
                angle += 3;
            else if (moveLeft)
                angle -= 3;

            if (angle >= 360)
                angle = 0;
            else if (angle <= -360)
                angle = 0;

            if (dstRect.Y < -60)
                dyOffset += this.Height - 120;
            else if (dstRect.Y > 750)
                dyOffset -= 750;
            else if (dstRect.X < -50 || dstRect.X > 1580)
            {
                movement_tick.Enabled = false;
                canDraw = false;
                failedCount++;
            }

            double radians = (Math.PI / 180) * angle;
            dxOffset += Math.Cos(radians) * speed;
            dyOffset += Math.Sin(radians) * speed;

            //Check earth
            double dist = Math.Abs( Math.Pow((dstRect.X + 24) - (earthRect.X + 50), 2) + Math.Pow((dstRect.Y+24) - (earthRect.Y+50), 2));
            if(dist <= 800)
            {
                movement_tick.Enabled = false;
                canDraw = false;
                successCount++;
                startButton.Text = "Reset";
            }

            //Check asteroids
            for(int i = 0; i < asteroids.Length; i++)
            {
                dist = Math.Abs(Math.Pow((dstRect.X + 24) - (asteroids[i].x + 72), 2) + Math.Pow((dstRect.Y + 24) - (asteroids[i].y + 72), 2));
                if (dist <= 8000)
                {
                    movement_tick.Enabled = false;
                    canDraw = false;
                    failedCount++;
                    startButton.Text = "Reset";
                }
            }


        }
        protected void asteroid_movement(System.Object sender, ElapsedEventArgs evt)
        {
            for (int i = 0; i < asteroids.Length; i++)
            {
                if (asteroids[i].y < -150)
                    asteroids[i].y += 900;
                else if (asteroids[i].y > 850)
                    asteroids[i].y -= 950;

                double radians = (Math.PI / 180) * asteroids[i].dir;
                asteroids[i].x += Math.Cos(radians) * asteroids[i].speed;
                asteroids[i].y += Math.Sin(radians) * asteroids[i].speed;

            }
        }

        //Drawing functions
        protected override void OnPaint(PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            Graphics gg = Graphics.FromImage(bmp);
            dstRect = new Rectangle(Convert.ToInt32(dxOffset), Convert.ToInt32(dyOffset), 48, 48);
            Rectangle spaceRect = new Rectangle(0, this.Height - 150, this.Width, 120);
            Rectangle compassRect = new Rectangle(768, 750, 5, 50);
            Brush spaceBrush = new SolidBrush(Color.FromArgb(250, 19, 13, 15));
            earthRect = new Rectangle(1530, 330, 100, 100);
            //Earth
            g.FillEllipse(Brushes.Blue, earthRect);

            //Mars
            g.FillEllipse(Brushes.Red, new Rectangle(-50, 330, 100, 100));

            //Can we draw the astroids now?
            if (canDraw)
                //Astroids
                for(int i = 0; i < asteroids.Length; i++)
                    g.FillEllipse(Brushes.Gray, new Rectangle(Convert.ToInt32(asteroids[i].x), Convert.ToInt32(asteroids[i].y), 144, 144));

            //Space ship angle transformation
            Point[] Points = {
                    new Point(dstRect.Left, dstRect.Top),
                    new Point(dstRect.Right, dstRect.Top),
                    new Point(dstRect.Left, dstRect.Bottom)
                };
            Matrix myMatrix = new Matrix(dstRect, Points);
            myMatrix.RotateAt(angle, new Point(dstRect.Left + dstRect.Width / 2,
                     dstRect.Top + dstRect.Height / 2));
            g.Transform = myMatrix;
            g.DrawImage(bmp, dstRect, 0, 0, bmp.Width, bmp.Height,
                GraphicsUnit.Pixel, attr);

            //Opaque Control angle transformation
            Point[] Points3 = {
                new Point(spaceRect.Left, spaceRect.Top),
                new Point(spaceRect.Right, spaceRect.Top),
                new Point(spaceRect.Left, spaceRect.Bottom)
            };
            Matrix myMatrix3 = new Matrix(spaceRect, Points3);
            myMatrix3.RotateAt(0, new Point(dstRect.Left + dstRect.Width / 2,
                     dstRect.Top + dstRect.Height / 2));
            g.Transform = myMatrix3;
            //Opaque Control Background
            g.FillRectangle(spaceBrush, spaceRect);
            g.FillEllipse(Brushes.White, new Rectangle(730, 750, 80, 80));

            //Compass angle transformation
            Point[] Points2 = {
                new Point(compassRect.Left, compassRect.Top),
                new Point(compassRect.Right, compassRect.Top),
                new Point(compassRect.Left, compassRect.Bottom)
            };

            Matrix myMatrix2 = new Matrix(compassRect, Points2);
            myMatrix2.RotateAt(angle + 90, new Point(770, 790));
            g.Transform = myMatrix2;
            //Compass design
            g.FillRectangle(Brushes.Aqua, compassRect);

            //Text
            successJourneyCount.Text = successCount.ToString();
            failedJourneyCount.Text = failedCount.ToString();
            gg.Dispose();
            base.OnPaint(e);
        }
        protected void startGraphicalClock()
        {
            double elapsedtimebetweentics;
            elapsedtimebetweentics = 1000.0 / RefreshRate;  //elapsedtimebetweentics has units milliseconds.
            graphic_area_refresh_clock.Interval = (int)System.Math.Round(elapsedtimebetweentics);
            graphic_area_refresh_clock.Enabled = true;  //Start clock ticking.
            ship_clock_active = true;
        }
        protected void updateDisplay(System.Object sender, ElapsedEventArgs evt)
        {
            Invalidate();

            if (!(ship_clock_active))
                graphic_area_refresh_clock.Enabled = false;
        }
        
        //Keyboard key handler functions
        private void GoHome_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.A:
                case Keys.Left:
                case Keys.Right:
                case Keys.D:
                case Keys.ShiftKey:
                case Keys.Enter:
                    e.IsInputKey = true;
                    break;
            }
        }
        protected override void OnKeyUp(KeyEventArgs e)
        {

            switch (e.KeyCode)
            {
                case Keys.A:
                case Keys.Left:
                    moveLeft = false;
                    break;
                case Keys.D:
                case Keys.Right:
                    moveRight = false;
                    break;
            }

        }
        protected override void OnKeyDown(KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.A:
                case Keys.Left:
                    moveRight = false;
                    moveLeft = true;
                    break;
                case Keys.D:
                case Keys.Right:
                    moveLeft = false;
                    moveRight = true;
                    break;
                case Keys.Oemtilde:
                case Keys.Escape:
                    toggleDeveloperConsole();
                    developerConsole.Focus();
                    break;
            }
        }

        //Developer console functions 
        protected void toggleDeveloperConsole()
        {
            if (openConsole)
            {
                developerConsole.Text = "";
                developerConsole.Visible = true;
                developerConsole.Enabled = true;
                openConsole = false;
            }
            else
            {
                developerConsole.Visible = false;
                developerConsole.Enabled = false;
                openConsole = true;
            }
            Invalidate();
        }
        protected void validateCommand()
        {
            if (developerConsole.Text.Length == 0) return;
            string t = developerConsole.Text;
            t = t.ToLower();
            string[] buffer;
            buffer = t.Split(null as string[], StringSplitOptions.RemoveEmptyEntries);
            for (int i = 0; i < commands.Length; i++)
            {
                if (buffer[0] == commands[i])
                {
                    switch (i)
                    {
                        case 0: //Close
                            Console.WriteLine("Closing form because the console told me to.");
                            Close();
                            break;
                        case 1: //Move
                            if ((buffer.Length - 1) == 2)
                            {
                                dxOffset = Convert.ToDouble(buffer[1]);
                                dyOffset = Convert.ToDouble(buffer[2]);
                            }
                            else
                            {
                                developerConsole.Select(0, developerConsole.Text.Length);
                                Console.WriteLine("Invalid arguments. Requires 2, given {0}", buffer.Length - 1);
                            }
                            break;
                        case 2: //Set
                            bool hasFound = false;
                            if ((buffer.Length - 1) == 2)
                            {
                                for(int k = 0; k < properties.Length; k++)
                                {
                                    if (buffer[1] == properties[k])
                                    {
                                        Console.WriteLine("Setting property value of {0} to {1}!", k, k);
                                        hasFound = true;
                                        switch ( k )
                                        {
                                            case 0: 
                                                successCount = Convert.ToInt32(buffer[2]);
                                                break;
                                            case 1:
                                                failedCount = Convert.ToInt32(buffer[2]);
                                                break;
                                        }
                                        Invalidate();
                                    }    
                                    else if(k == properties.Length - 1 && hasFound == false)
                                        Console.WriteLine("Invalid argument. Property '{0}' not found.", buffer[1]);
                                }
                            }
                            else
                            {
                                developerConsole.Select(0, developerConsole.Text.Length);
                                Console.WriteLine("Invalid arguments. Requires 2, given {0}", buffer.Length - 1);
                            }
                            break;
                        case 3: //Reset
                            graphic_area_refresh_clock.Enabled = false;
                            movement_tick.Enabled = false;
                            asteroid_movement_tick.Enabled = false;
                            angle = 0;
                            dxOffset = 0.0;
                            dyOffset = 350.0;
                            Console.WriteLine("Form reset complete.");
                            break;
                        case 4: //Help
                            Console.WriteLine("- - - - - - - - - Help menu - - - - - - - - -");
                            Console.WriteLine("move X Y | Moves the space ship to X and Y coordinates.");
                            Console.WriteLine("set PROPERTY_NAME VALUE  | Sets a PROPERTY_NAME's value to VALUE.");
                            Console.WriteLine("reset | Restarts the form completely.");
                            Console.WriteLine("close | Closes the form. Shortcut instead of clicking \'stop\'");
                            break;
                    }
                }
                else if(buffer.Length < 2 && i == commands.Length-1) {
                    developerConsole.Select(0, developerConsole.Text.Length);
                    break;
                }
            }
        }
        private void developerConsole_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)13)
                validateCommand();
            else if (e.KeyChar == (char)27 || e.KeyChar == (char)96)
                toggleDeveloperConsole();
        }

        //Button handling functions
        private void startButton_Click(object sender, EventArgs e)
        {
            if (!canDraw && startButton.Text != "Reset") {
                dstRect.X = 0;
                dstRect.Y = 0;
                angle = 0;
                dxOffset = 0.0;
                dyOffset = 350.0;
                canDraw = true;
                startGraphicalClock();
                movement_tick.Enabled = true;
                asteroid_movement_tick.Enabled = true;
                startButton.Text = "Reset";
                random = new Random();
                asteroids[0] = new asteroid(800, 0, random.Next(0, 360));
                asteroids[1] = new asteroid(500, 600, random.Next(0, 360));
                asteroids[2] = new asteroid(1100, 600, random.Next(0, 360));
            }
            else { 
                dstRect.X = 0;
                dstRect.Y = 0;
                angle = 0;
                dxOffset = 0.0;
                dyOffset = 350.0;
                canDraw = false;
                movement_tick.Enabled = false;
                asteroid_movement_tick.Enabled = false;
                graphic_area_refresh_clock.Enabled = false;
                for (int i = 0; i < asteroids.Length; i++)
                    asteroids[i].reset();
                    startButton.Text = "Start";
                random = new Random();
                asteroids[0] = new asteroid(800, 0, random.Next(0, 360));
                asteroids[1] = new asteroid(500, 600, random.Next(0, 360));
                asteroids[2] = new asteroid(1100, 600, random.Next(0, 360));
                Invalidate();
            }
            this.ActiveControl = null;
        }
        private void exitButton_Click(object sender, EventArgs e)
        {
            this.ActiveControl = null;
            Close();
        }
    }
}
