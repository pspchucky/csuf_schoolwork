using System.Windows.Forms;

namespace WindowsFormsApplication2
{
    partial class Form1
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

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.label1 = new System.Windows.Forms.Label();
            this.tableLayoutPanel2 = new System.Windows.Forms.TableLayoutPanel();
            this.resetButton = new System.Windows.Forms.Button();
            this.exitButton = new System.Windows.Forms.Button();
            this.refreshRate = new System.Windows.Forms.TextBox();
            this.goButton = new System.Windows.Forms.Button();
            this.xBallPos = new System.Windows.Forms.Label();
            this.yBallPos = new System.Windows.Forms.Label();
            this.directionLabel = new System.Windows.Forms.Label();
            this.tableLayoutPanel1.SuspendLayout();
            this.tableLayoutPanel2.SuspendLayout();
            this.SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 1;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel1.Controls.Add(this.label1, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.tableLayoutPanel2, 0, 2);
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(0, 0);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 3;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 10F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 70F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 20F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(1264, 1001);
            this.tableLayoutPanel1.TabIndex = 0;
            this.tableLayoutPanel1.CellPaint += new System.Windows.Forms.TableLayoutCellPaintEventHandler(this.tableLayoutPanel1_CellPaint);
            // 
            // label1
            // 
            this.label1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(211)))), ((int)(((byte)(255)))), ((int)(((byte)(208)))));
            this.label1.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.label1.Font = new System.Drawing.Font("Comic Sans MS", 20.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(3, 31);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(1258, 38);
            this.label1.TabIndex = 0;
            this.label1.Text = "Animation by Sergio German";
            this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // tableLayoutPanel2
            // 
            this.tableLayoutPanel2.ColumnCount = 6;
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 16.13672F));
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 9.300477F));
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 6.438792F));
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 36.72496F));
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 10.81081F));
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 20.42925F));
            this.tableLayoutPanel2.Controls.Add(this.resetButton, 1, 2);
            this.tableLayoutPanel2.Controls.Add(this.exitButton, 2, 2);
            this.tableLayoutPanel2.Controls.Add(this.refreshRate, 1, 0);
            this.tableLayoutPanel2.Controls.Add(this.goButton, 0, 2);
            this.tableLayoutPanel2.Controls.Add(this.xBallPos, 3, 2);
            this.tableLayoutPanel2.Controls.Add(this.yBallPos, 5, 2);
            this.tableLayoutPanel2.Controls.Add(this.directionLabel, 4, 0);
            this.tableLayoutPanel2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel2.Location = new System.Drawing.Point(3, 803);
            this.tableLayoutPanel2.Name = "tableLayoutPanel2";
            this.tableLayoutPanel2.RowCount = 3;
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 60.31746F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 39.68254F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 68F));
            this.tableLayoutPanel2.Size = new System.Drawing.Size(1258, 195);
            this.tableLayoutPanel2.TabIndex = 1;
            this.tableLayoutPanel2.CellPaint += new System.Windows.Forms.TableLayoutCellPaintEventHandler(this.tableLayoutPanel2_CellPaint);
            // 
            // resetButton
            // 
            this.resetButton.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.resetButton.BackColor = System.Drawing.Color.White;
            this.resetButton.Enabled = false;
            this.resetButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.resetButton.Font = new System.Drawing.Font("Comic Sans MS", 13.75F);
            this.resetButton.Location = new System.Drawing.Point(224, 129);
            this.resetButton.Name = "resetButton";
            this.resetButton.Size = new System.Drawing.Size(75, 50);
            this.resetButton.TabIndex = 4;
            this.resetButton.Text = "Reset";
            this.resetButton.UseVisualStyleBackColor = false;
            this.resetButton.Click += new System.EventHandler(this.resetButton_Click);
            // 
            // exitButton
            // 
            this.exitButton.BackColor = System.Drawing.Color.White;
            this.exitButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.exitButton.Font = new System.Drawing.Font("Comic Sans MS", 13.75F);
            this.exitButton.Location = new System.Drawing.Point(323, 129);
            this.exitButton.Name = "exitButton";
            this.exitButton.Size = new System.Drawing.Size(75, 50);
            this.exitButton.TabIndex = 5;
            this.exitButton.Text = "Exit";
            this.exitButton.UseVisualStyleBackColor = false;
            this.exitButton.Click += new System.EventHandler(this.exitButton_Click);
            // 
            // refreshRate
            // 
            this.refreshRate.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.refreshRate.BackColor = System.Drawing.Color.White;
            this.refreshRate.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.refreshRate.Enabled = false;
            this.refreshRate.Font = new System.Drawing.Font("Comic Sans MS", 15.75F);
            this.refreshRate.Location = new System.Drawing.Point(226, 18);
            this.refreshRate.Multiline = true;
            this.refreshRate.Name = "refreshRate";
            this.refreshRate.Size = new System.Drawing.Size(70, 40);
            this.refreshRate.TabIndex = 6;
            this.refreshRate.Text = "30";
            this.refreshRate.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.refreshRate.TextChanged += new System.EventHandler(this.textBox3_TextChanged);
            // 
            // goButton
            // 
            this.goButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.goButton.BackColor = System.Drawing.Color.White;
            this.goButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.goButton.Font = new System.Drawing.Font("Comic Sans MS", 13.75F);
            this.goButton.Location = new System.Drawing.Point(125, 129);
            this.goButton.Name = "goButton";
            this.goButton.Size = new System.Drawing.Size(75, 50);
            this.goButton.TabIndex = 3;
            this.goButton.Text = "Go";
            this.goButton.UseVisualStyleBackColor = false;
            this.goButton.Click += new System.EventHandler(this.goButton_Click);
            // 
            // xBallPos
            // 
            this.xBallPos.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.xBallPos.AutoSize = true;
            this.xBallPos.BackColor = System.Drawing.Color.White;
            this.xBallPos.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.xBallPos.Font = new System.Drawing.Font("Comic Sans MS", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.xBallPos.Location = new System.Drawing.Point(692, 126);
            this.xBallPos.Name = "xBallPos";
            this.xBallPos.Size = new System.Drawing.Size(168, 37);
            this.xBallPos.TabIndex = 7;
            this.xBallPos.Text = "X Coordinate";
            // 
            // yBallPos
            // 
            this.yBallPos.AutoSize = true;
            this.yBallPos.BackColor = System.Drawing.Color.White;
            this.yBallPos.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.yBallPos.Font = new System.Drawing.Font("Comic Sans MS", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.yBallPos.Location = new System.Drawing.Point(1002, 126);
            this.yBallPos.Name = "yBallPos";
            this.yBallPos.Size = new System.Drawing.Size(166, 37);
            this.yBallPos.TabIndex = 8;
            this.yBallPos.Text = "Y Coordinate";
            // 
            // directionLabel
            // 
            this.directionLabel.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
            this.directionLabel.AutoSize = true;
            this.directionLabel.BackColor = System.Drawing.Color.White;
            this.directionLabel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.directionLabel.Font = new System.Drawing.Font("Comic Sans MS", 18F, System.Drawing.FontStyle.Bold);
            this.directionLabel.Location = new System.Drawing.Point(870, 39);
            this.directionLabel.Name = "directionLabel";
            this.directionLabel.Size = new System.Drawing.Size(122, 37);
            this.directionLabel.TabIndex = 9;
            this.directionLabel.Text = "Direction";
            // 
            // Form1
            // 
            this.ClientSize = new System.Drawing.Size(1264, 1001);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Name = "Form1";
            this.SizeChanged += new System.EventHandler(this.Form1_SizeChanged);
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel1.PerformLayout();
            this.tableLayoutPanel2.ResumeLayout(false);
            this.tableLayoutPanel2.PerformLayout();
            this.ResumeLayout(false);

        }
        private TableLayoutPanel tableLayoutPanel1;
        private Label label1;
        private TableLayoutPanel tableLayoutPanel2;
        private Button goButton;
        private Button resetButton;
        private Button exitButton;
        private TextBox refreshRate;
        private Label xBallPos;
        private Label yBallPos;
        private Label directionLabel;
    }
}

