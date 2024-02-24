import smtplib
import time
from email.mime.text import MIMEText
import subprocess
import re


def get_ipv6_from_ifconfig(interface):
    try:
        # 使用subprocess运行ifconfig命令，捕获输出
        result = subprocess.run(['ifconfig', interface], capture_output=True, text=True)
        output = result.stdout

        # 使用正则表达式匹配所有IPv6地址
        ipv6_pattern = re.compile(r'inet6(?: addr:)? ([\w:]+)')

        # 查找所有匹配的IPv6地址
        matches = ipv6_pattern.findall(output)

        if matches:
            ipv6_addresses = matches
            return ipv6_addresses
        else:
            print(f"No IPv6 address found for {interface}")
            return None

    except FileNotFoundError:
        print(f"Command 'ifconfig' not found.")


def read_syslog():
    log_file_path1 = '/var/log/syslog'
    try:
        # 使用subprocess运行tail命令，捕获输出
        result1 = subprocess.run(['tail', log_file_path1], capture_output=True, text=True)
        # 输出结果
        syslog_content = result1.stdout
        return syslog_content
    except FileNotFoundError:
        print(f"File '{log_file_path1}' not found.")


def read_faillog():
    log_file_path2 = '/var/log/faillog'
    try:
        # 使用subprocess运行tail命令，捕获输出
        result2 = subprocess.run(['tail', log_file_path2], capture_output=True, text=True)
        # 输出结果
        faillog_content = result2.stdout
        return faillog_content
    except FileNotFoundError:
        print(f"File '{log_file_path2}' not found.")


def send_email(subject, body):
    # 请替换为您的邮件配置
    sender_email = "2671199174@qq.com"
    sender_password = "caxtamwaxcpgdjia"
    recipient_email = "hahahabigw@gmail.com"

    # 创建邮件
    message = MIMEText(body)
    message["Subject"] = subject
    message["From"] = sender_email
    message["To"] = recipient_email

    # 连接到SMTP服务器并发送邮件
    with smtplib.SMTP_SSL("smtp.qq.com", 465) as server:
        time.sleep(2)  # 延迟2秒
        server.login(sender_email, sender_password)
        server.sendmail(sender_email, recipient_email, message.as_string())


def main():
    syslog = read_syslog()
    faillog = read_faillog()
    wlan0_ipv6_addresses = get_ipv6_from_ifconfig('wlan0')

    subject = f"Daily Report 😄"
    body = f"IPv6 Addresses:\n{wlan0_ipv6_addresses}\n\nSyslog:\n{syslog}\n\nFail log:\n{faillog}"
    send_email(subject, body)
    print(f"daily report done !")


if __name__ == "__main__":
    main()
