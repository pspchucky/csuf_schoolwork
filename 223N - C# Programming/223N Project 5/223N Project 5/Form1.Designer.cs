namespace _223N_Project_5
{
    partial class GoHome
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(GoHome));
            this.startButton = new System.Windows.Forms.Button();
            this.exitButton = new System.Windows.Forms.Button();
            this.successfulJourneysLbl = new System.Windows.Forms.Label();
            this.disastrousJourneysLbl = new System.Windows.Forms.Label();
            this.developerConsole = new System.Windows.Forms.TextBox();
            this.failedJourneyCount = new System.Windows.Forms.Label();
            this.successJourneyCount = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // startButton
            // 
            this.startButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.startButton.Font = new System.Drawing.Font("Comic Sans MS", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.startButton.Location = new System.Drawing.Point(80, 771);
            this.startButton.Name = "startButton";
            this.startButton.Size = new System.Drawing.Size(120, 50);
            this.startButton.TabIndex = 0;
            this.startButton.TabStop = false;
            this.startButton.Text = "Start";
            this.startButton.UseVisualStyleBackColor = true;
            this.startButton.Click += new System.EventHandler(this.startButton_Click);
            // 
            // exitButton
            // 
            this.exitButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.exitButton.Font = new System.Drawing.Font("Comic Sans MS", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.exitButton.Location = new System.Drawing.Point(280, 771);
            this.exitButton.Name = "exitButton";
            this.exitButton.Size = new System.Drawing.Size(120, 50);
            this.exitButton.TabIndex = 1;
            this.exitButton.TabStop = false;
            this.exitButton.Text = "Exit";
            this.exitButton.UseVisualStyleBackColor = true;
            this.exitButton.Click += new System.EventHandler(this.exitButton_Click);
            // 
            // successfulJourneysLbl
            // 
            this.successfulJourneysLbl.AutoSize = true;
            this.successfulJourneysLbl.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(19)))), ((int)(((byte)(13)))), ((int)(((byte)(15)))));
            this.successfulJourneysLbl.Font = new System.Drawing.Font("Comic Sans MS", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.successfulJourneysLbl.ForeColor = System.Drawing.Color.White;
            this.successfulJourneysLbl.Location = new System.Drawing.Point(1042, 763);
            this.successfulJourneysLbl.Name = "successfulJourneysLbl";
            this.successfulJourneysLbl.Size = new System.Drawing.Size(215, 29);
            this.successfulJourneysLbl.TabIndex = 3;
            this.successfulJourneysLbl.Text = "Successful Journeys";
            // 
            // disastrousJourneysLbl
            // 
            this.disastrousJourneysLbl.AutoSize = true;
            this.disastrousJourneysLbl.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(19)))), ((int)(((byte)(13)))), ((int)(((byte)(15)))));
            this.disastrousJourneysLbl.Font = new System.Drawing.Font("Comic Sans MS", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.disastrousJourneysLbl.ForeColor = System.Drawing.Color.White;
            this.disastrousJourneysLbl.Location = new System.Drawing.Point(1360, 763);
            this.disastrousJourneysLbl.Name = "disastrousJourneysLbl";
            this.disastrousJourneysLbl.Size = new System.Drawing.Size(212, 29);
            this.disastrousJourneysLbl.TabIndex = 4;
            this.disastrousJourneysLbl.Text = "Disastrous Journeys";
            // 
            // developerConsole
            // 
            this.developerConsole.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.developerConsole.Enabled = false;
            this.developerConsole.Location = new System.Drawing.Point(13, 13);
            this.developerConsole.Name = "developerConsole";
            this.developerConsole.Size = new System.Drawing.Size(387, 20);
            this.developerConsole.TabIndex = 5;
            this.developerConsole.Visible = false;
            this.developerConsole.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.developerConsole_KeyPress);
            // 
            // failedJourneyCount
            // 
            this.failedJourneyCount.AutoSize = true;
            this.failedJourneyCount.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(19)))), ((int)(((byte)(13)))), ((int)(((byte)(15)))));
            this.failedJourneyCount.Font = new System.Drawing.Font("Comic Sans MS", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.failedJourneyCount.ForeColor = System.Drawing.Color.White;
            this.failedJourneyCount.Location = new System.Drawing.Point(1462, 792);
            this.failedJourneyCount.Name = "failedJourneyCount";
            this.failedJourneyCount.Size = new System.Drawing.Size(26, 29);
            this.failedJourneyCount.TabIndex = 7;
            this.failedJourneyCount.Text = "0";
            // 
            // successJourneyCount
            // 
            this.successJourneyCount.AutoSize = true;
            this.successJourneyCount.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(19)))), ((int)(((byte)(13)))), ((int)(((byte)(15)))));
            this.successJourneyCount.Font = new System.Drawing.Font("Comic Sans MS", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.successJourneyCount.ForeColor = System.Drawing.Color.White;
            this.successJourneyCount.Location = new System.Drawing.Point(1143, 792);
            this.successJourneyCount.Name = "successJourneyCount";
            this.successJourneyCount.Size = new System.Drawing.Size(26, 29);
            this.successJourneyCount.TabIndex = 6;
            this.successJourneyCount.Text = "0";
            // 
            // GoHome
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.ClientSize = new System.Drawing.Size(1584, 861);
            this.Controls.Add(this.failedJourneyCount);
            this.Controls.Add(this.successJourneyCount);
            this.Controls.Add(this.developerConsole);
            this.Controls.Add(this.disastrousJourneysLbl);
            this.Controls.Add(this.successfulJourneysLbl);
            this.Controls.Add(this.exitButton);
            this.Controls.Add(this.startButton);
            this.DoubleBuffered = true;
            this.Name = "GoHome";
            this.Text = "Go Home";
            this.PreviewKeyDown += new System.Windows.Forms.PreviewKeyDownEventHandler(this.GoHome_PreviewKeyDown);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button startButton;
        private System.Windows.Forms.Button exitButton;
        private System.Windows.Forms.Label successfulJourneysLbl;
        private System.Windows.Forms.Label disastrousJourneysLbl;
        private System.Windows.Forms.TextBox developerConsole;
        private System.Windows.Forms.Label failedJourneyCount;
        private System.Windows.Forms.Label successJourneyCount;
    }
}

