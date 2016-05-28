namespace Project3
{
    partial class RicochetingBall
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.nameLabel = new System.Windows.Forms.Label();
            this.newButton = new System.Windows.Forms.Button();
            this.startButton = new System.Windows.Forms.Button();
            this.quitButton = new System.Windows.Forms.Button();
            this.refreshRateLbl = new System.Windows.Forms.Label();
            this.speedLbl = new System.Windows.Forms.Label();
            this.directionLbl = new System.Windows.Forms.Label();
            this.coordLbl = new System.Windows.Forms.Label();
            this.xEqualsLbl = new System.Windows.Forms.Label();
            this.yEqualsLbl = new System.Windows.Forms.Label();
            this.yCoords = new System.Windows.Forms.Label();
            this.xCoords = new System.Windows.Forms.Label();
            this.refreshRateBox = new System.Windows.Forms.TextBox();
            this.speedBox = new System.Windows.Forms.TextBox();
            this.degreesBox = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // nameLabel
            // 
            this.nameLabel.AutoSize = true;
            this.nameLabel.BackColor = System.Drawing.Color.LightBlue;
            this.nameLabel.Font = new System.Drawing.Font("Comic Sans MS", 26.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.nameLabel.Location = new System.Drawing.Point(520, 0);
            this.nameLabel.Name = "nameLabel";
            this.nameLabel.Size = new System.Drawing.Size(558, 49);
            this.nameLabel.TabIndex = 0;
            this.nameLabel.Text = "Ricochet Ball by Sergio German";
            // 
            // newButton
            // 
            this.newButton.BackColor = System.Drawing.Color.White;
            this.newButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.newButton.Location = new System.Drawing.Point(149, 775);
            this.newButton.Name = "newButton";
            this.newButton.Size = new System.Drawing.Size(70, 25);
            this.newButton.TabIndex = 1;
            this.newButton.Text = "New";
            this.newButton.UseVisualStyleBackColor = false;
            this.newButton.Click += new System.EventHandler(this.newButton_Click);
            // 
            // startButton
            // 
            this.startButton.BackColor = System.Drawing.Color.White;
            this.startButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.startButton.Location = new System.Drawing.Point(677, 775);
            this.startButton.Name = "startButton";
            this.startButton.Size = new System.Drawing.Size(70, 25);
            this.startButton.TabIndex = 2;
            this.startButton.Text = "Start";
            this.startButton.UseVisualStyleBackColor = false;
            this.startButton.Click += new System.EventHandler(this.startButton_Click);
            // 
            // quitButton
            // 
            this.quitButton.BackColor = System.Drawing.Color.White;
            this.quitButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.quitButton.Location = new System.Drawing.Point(1162, 775);
            this.quitButton.Name = "quitButton";
            this.quitButton.Size = new System.Drawing.Size(70, 25);
            this.quitButton.TabIndex = 3;
            this.quitButton.Text = "Quit";
            this.quitButton.UseVisualStyleBackColor = false;
            this.quitButton.Click += new System.EventHandler(this.quitButton_Click);
            // 
            // refreshRateLbl
            // 
            this.refreshRateLbl.AutoSize = true;
            this.refreshRateLbl.BackColor = System.Drawing.Color.LightGoldenrodYellow;
            this.refreshRateLbl.Location = new System.Drawing.Point(136, 803);
            this.refreshRateLbl.Name = "refreshRateLbl";
            this.refreshRateLbl.Size = new System.Drawing.Size(92, 13);
            this.refreshRateLbl.TabIndex = 4;
            this.refreshRateLbl.Text = "Refresh Rate (Hz)";
            // 
            // speedLbl
            // 
            this.speedLbl.AutoSize = true;
            this.speedLbl.BackColor = System.Drawing.Color.LightGoldenrodYellow;
            this.speedLbl.Location = new System.Drawing.Point(657, 803);
            this.speedLbl.Name = "speedLbl";
            this.speedLbl.Size = new System.Drawing.Size(108, 13);
            this.speedLbl.TabIndex = 5;
            this.speedLbl.Text = "Speed (pixel/second)";
            // 
            // directionLbl
            // 
            this.directionLbl.AutoSize = true;
            this.directionLbl.BackColor = System.Drawing.Color.LightGoldenrodYellow;
            this.directionLbl.Location = new System.Drawing.Point(1146, 803);
            this.directionLbl.Name = "directionLbl";
            this.directionLbl.Size = new System.Drawing.Size(96, 13);
            this.directionLbl.TabIndex = 6;
            this.directionLbl.Text = "Direction (degrees)";
            // 
            // coordLbl
            // 
            this.coordLbl.AutoSize = true;
            this.coordLbl.BackColor = System.Drawing.Color.LightGoldenrodYellow;
            this.coordLbl.Font = new System.Drawing.Font("Comic Sans MS", 12.75F);
            this.coordLbl.Location = new System.Drawing.Point(1438, 775);
            this.coordLbl.Name = "coordLbl";
            this.coordLbl.Size = new System.Drawing.Size(106, 24);
            this.coordLbl.TabIndex = 7;
            this.coordLbl.Text = "Coordinates";
            // 
            // xEqualsLbl
            // 
            this.xEqualsLbl.AutoSize = true;
            this.xEqualsLbl.BackColor = System.Drawing.Color.LightGoldenrodYellow;
            this.xEqualsLbl.Font = new System.Drawing.Font("Comic Sans MS", 10.75F);
            this.xEqualsLbl.Location = new System.Drawing.Point(1437, 806);
            this.xEqualsLbl.Name = "xEqualsLbl";
            this.xEqualsLbl.Size = new System.Drawing.Size(36, 20);
            this.xEqualsLbl.TabIndex = 8;
            this.xEqualsLbl.Text = "X = ";
            // 
            // yEqualsLbl
            // 
            this.yEqualsLbl.AutoSize = true;
            this.yEqualsLbl.BackColor = System.Drawing.Color.LightGoldenrodYellow;
            this.yEqualsLbl.Font = new System.Drawing.Font("Comic Sans MS", 10.75F);
            this.yEqualsLbl.Location = new System.Drawing.Point(1438, 832);
            this.yEqualsLbl.Name = "yEqualsLbl";
            this.yEqualsLbl.Size = new System.Drawing.Size(35, 20);
            this.yEqualsLbl.TabIndex = 9;
            this.yEqualsLbl.Text = "Y = ";
            // 
            // yCoords
            // 
            this.yCoords.AutoSize = true;
            this.yCoords.BackColor = System.Drawing.Color.White;
            this.yCoords.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.yCoords.Font = new System.Drawing.Font("Comic Sans MS", 10.75F);
            this.yCoords.Location = new System.Drawing.Point(1482, 832);
            this.yCoords.Name = "yCoords";
            this.yCoords.Size = new System.Drawing.Size(20, 22);
            this.yCoords.TabIndex = 14;
            this.yCoords.Text = "0";
            // 
            // xCoords
            // 
            this.xCoords.AutoSize = true;
            this.xCoords.BackColor = System.Drawing.Color.White;
            this.xCoords.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.xCoords.Font = new System.Drawing.Font("Comic Sans MS", 10.75F);
            this.xCoords.Location = new System.Drawing.Point(1482, 806);
            this.xCoords.Name = "xCoords";
            this.xCoords.Size = new System.Drawing.Size(20, 22);
            this.xCoords.TabIndex = 15;
            this.xCoords.Text = "0";
            // 
            // refreshRateBox
            // 
            this.refreshRateBox.Location = new System.Drawing.Point(149, 829);
            this.refreshRateBox.Name = "refreshRateBox";
            this.refreshRateBox.Size = new System.Drawing.Size(70, 20);
            this.refreshRateBox.TabIndex = 16;
            this.refreshRateBox.TextChanged += new System.EventHandler(this.refreshRateBox_TextChanged);
            // 
            // speedBox
            // 
            this.speedBox.Location = new System.Drawing.Point(677, 829);
            this.speedBox.Name = "speedBox";
            this.speedBox.Size = new System.Drawing.Size(70, 20);
            this.speedBox.TabIndex = 17;
            this.speedBox.TextChanged += new System.EventHandler(this.speedBox_TextChanged);
            // 
            // degreesBox
            // 
            this.degreesBox.Location = new System.Drawing.Point(1162, 829);
            this.degreesBox.Name = "degreesBox";
            this.degreesBox.Size = new System.Drawing.Size(70, 20);
            this.degreesBox.TabIndex = 18;
            this.degreesBox.TextChanged += new System.EventHandler(this.degreesBox_TextChanged);
            // 
            // RicochetingBall
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1584, 861);
            this.Controls.Add(this.degreesBox);
            this.Controls.Add(this.speedBox);
            this.Controls.Add(this.refreshRateBox);
            this.Controls.Add(this.xCoords);
            this.Controls.Add(this.yCoords);
            this.Controls.Add(this.yEqualsLbl);
            this.Controls.Add(this.xEqualsLbl);
            this.Controls.Add(this.coordLbl);
            this.Controls.Add(this.directionLbl);
            this.Controls.Add(this.speedLbl);
            this.Controls.Add(this.refreshRateLbl);
            this.Controls.Add(this.quitButton);
            this.Controls.Add(this.startButton);
            this.Controls.Add(this.newButton);
            this.Controls.Add(this.nameLabel);
            this.Name = "RicochetingBall";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Ricochet Ball by Sergio German";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label nameLabel;
        private System.Windows.Forms.Button newButton;
        private System.Windows.Forms.Button startButton;
        private System.Windows.Forms.Button quitButton;
        private System.Windows.Forms.Label refreshRateLbl;
        private System.Windows.Forms.Label speedLbl;
        private System.Windows.Forms.Label directionLbl;
        private System.Windows.Forms.Label coordLbl;
        private System.Windows.Forms.Label yEqualsLbl;
        private System.Windows.Forms.Label xEqualsLbl;
        private System.Windows.Forms.Label yCoords;
        private System.Windows.Forms.Label xCoords;
        private System.Windows.Forms.TextBox refreshRateBox;
        private System.Windows.Forms.TextBox speedBox;
        private System.Windows.Forms.TextBox degreesBox;
    }
}

